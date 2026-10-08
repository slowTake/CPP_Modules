# CPP06: C++ casts, study notes

The module rule: **each exercise must use a specific kind of cast, and you have
to defend your choice.** So first, the four C++ casts.

| Cast | What it does | Checked when? | Used in |
|---|---|---|---|
| `static_cast<T>(x)` | Conversions the compiler knows how to do safely: numeric types (int ↔ double ↔ char…), upcasts, `void*` → `T*` | Compile time | **ex00** |
| `reinterpret_cast<T>(x)` | "Look at these same bits as another type." Pointer ↔ integer, pointer ↔ unrelated pointer. Changes no value. | Not checked | **ex01** |
| `dynamic_cast<T>(x)` | Safe downcast in a polymorphic hierarchy (Base* → Derived*). Checks the real type of the object at runtime. | **Runtime** | **ex02** |
| `const_cast<T>(x)` | Adds or removes `const`/`volatile`. The only cast that can do this. | Compile time | not used |

A C-style cast `(int)x` silently tries `const_cast`, `static_cast` and
`reinterpret_cast` in turn. It's dangerous because you can't see which one you
got. The named casts make your intent explicit and easy to grep.

**Implicit vs explicit conversion:** `double d = 42;` is implicit (the compiler
does it on its own). `static_cast<int>(4.2)` is explicit (you ask for it and
take responsibility for losing the `.2`).

---

## ex00: ScalarConverter (`static_cast`)

### What it asks
`./convert <literal>` detects whether the literal is a char, int, float or
double, converts the string to **that** type, then explicitly converts it to the
other three and prints all four.

### Why the class can't be instantiated
It only has a static method and stores nothing. The constructor, copy
constructor, assignment operator and destructor are all **private**, so
`ScalarConverter s;` doesn't compile. That still satisfies OCF: the four members
exist, they just aren't accessible.

### Step by step (`ScalarConverter.cpp`)
1. **`detectType()`** checks the string's shape, in this order:
   - pseudo-literals: `nanf +inff -inff` → float, `nan +inf -inf` → double
   - char: `'c'` (with quotes), or one character that isn't a digit (`a`).
     A single digit like `5` counts as an int, not a char.
   - int: `[+-]digits`
   - float: `[+-]digits.digits` followed by `f`
   - double: `[+-]digits.digits`
   - anything else → invalid
2. **Convert to the real type:** `std::strtol` for ints (with an overflow
   check), `std::strtod` for float and double. `strtod` stops at the trailing
   `f` and already understands `nan`/`inf`.
3. **Explicit conversion:** the value is widened to `double`. Every char, int and
   float fits *exactly* in a double, so no information is lost. Each printer
   then does `static_cast<char>`, `static_cast<int>` or `static_cast<float>`.

### Why `static_cast`?
These are conversions between arithmetic types. The compiler knows exactly how
to turn a double into an int (truncation) or a float into a double.
`static_cast` exists for that. `reinterpret_cast` would be wrong here, because
it would reinterpret the bit pattern of a double as an int and give garbage.

### Edge cases to know for the defense
- **NaN:** `nan != nan` is always true, so `d != d` detects NaN. `std::isnan`
  is C++11, so we can't use it.
- **char "impossible" vs "Non displayable":**
  - impossible: NaN, inf, or outside the char range (-128..127)
  - Non displayable: in range, but `isprint()` is false (0–31, 127)
- **int impossible:** NaN, inf, or outside `INT_MIN..INT_MAX`.
  `2147483648` is still shown as float and double, but int is impossible.
- **float impossible:** a finite double bigger than `FLT_MAX` (~3.4e38).
- **`.0` display:** `std::cout << 42.0` prints `42`. Whole numbers are
  therefore printed with `std::fixed` and `setprecision(1)` to get `42.0`.
- **Precision:** `4.2f` is really `4.19999980926…` in memory. The double line
  is printed with the source type's precision (6 digits for a float), so it
  shows `4.2`, not the rounding noise.
- `std::numeric_limits<T>` (in `<limits>`) gives `min()`, `max()`,
  `infinity()` and `digits10`, with no magic numbers needed.

### Try these
```
./convert 0        ./convert nan      ./convert 42.0f    ./convert a
./convert -42      ./convert 4.2f     ./convert 2147483648
./convert +inff    ./convert 128      ./convert hello
```

---

## ex01: Serializer (`reinterpret_cast`)

### What it asks
Convert a `Data*` to an integer (`uintptr_t`) and back, and prove the pointer
you get back equals the original.

### Key ideas
- A pointer is just a memory address, a number. **Serialization** here means
  turning that address into a plain integer (something you could store or send)
  and later turning it back.
- **`uintptr_t`** is an unsigned integer type guaranteed to be big enough to
  hold a pointer (64 bits on your machine). It comes from `<stdint.h>`, because
  `<cstdint>` is C++11.
- Like ex00, `Serializer` has private OCF members, so it can't be instantiated.
- `Data` must be non-empty, so it has `id`, `name` and `value`.

### Why `reinterpret_cast`?
Pointer ↔ integer is not a "value conversion" the compiler understands, so
`static_cast` refuses it and gives a compile error. `reinterpret_cast` says
"keep the exact same bits, just treat them as another type". That is precisely
what we want: the integer *is* the address. Going there and back with
`reinterpret_cast` is guaranteed to give the original pointer.

### Important
- No copy of the data is made. `deserialize` gives back a pointer to the
  **same** object, so if that object is destroyed, the integer becomes a
  dangling address.
- The main prints the address in hex and decimal so you can see it's the same
  number.

---

## ex02: Identify real type (`dynamic_cast`)

### What it asks
`Base` has only a virtual destructor. `A`, `B` and `C` inherit from it.
`generate()` randomly creates one of them. `identify(Base*)` and
`identify(Base&)` print the real type, **without `<typeinfo>`** (no `typeid`).

### Key ideas
- **Polymorphism needs a virtual function.** The virtual destructor makes
  `Base` polymorphic, so every object carries a hidden pointer to its vtable,
  which records its real type. `dynamic_cast` reads that at runtime. Without a
  virtual function, `dynamic_cast` on `Base` won't even compile.
- The virtual destructor also makes `delete p` (with `p` a `Base*`) correctly
  destroy the real `A`/`B`/`C`.
- **Upcast** (A* → Base*) is always safe and implicit; that's what `generate`
  does when it returns. A **downcast** (Base* → A*) might be wrong, which is why
  it needs a runtime check.

### Pointer vs reference version
| | Failure behaviour | How we test it |
|---|---|---|
| `dynamic_cast<A*>(p)` | returns `NULL` | `if (dynamic_cast<A*>(p))` |
| `dynamic_cast<A&>(p)` | **throws** `std::bad_cast` (a reference can't be NULL) | `try { … } catch (...) {}` |

`std::bad_cast` is declared in `<typeinfo>`, which is forbidden, so we catch
with `catch (...)` (catch anything). Inside `identify(Base&)` we never use a
pointer, as the subject requires.

### Why `dynamic_cast`?
It's the only cast that checks the object's **actual** type at runtime.
`static_cast<A*>(p)` would compile and "succeed" even if `p` points to a `B`,
which is undefined behaviour.

### Other details
- `std::srand(std::time(NULL))` in main seeds the random generator so each run
  is different. `std::rand() % 3` picks A, B or C.
- Every `generate()` result is `delete`d, so valgrind is clean.
- A plain `Base` object prints "Unknown type", because all three casts fail.

---

## Quick defense checklist
- [ ] Can I name the four casts and when to use each?
- [ ] Why can't ScalarConverter/Serializer be instantiated? (private constructors)
- [ ] How do I detect NaN without `isnan`? (`d != d`)
- [ ] Why does `static_cast` refuse pointer → integer?
- [ ] Why does `dynamic_cast` need a virtual function?
- [ ] What happens when `dynamic_cast` fails on a pointer vs a reference?
- [ ] Why `catch (...)` instead of `catch (std::bad_cast&)`?
