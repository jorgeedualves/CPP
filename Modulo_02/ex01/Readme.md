### Diagrama de Classe:
```mermaid
classDiagram
    class Fixed {
        +Fixed()
        +Fixed(const Fixed&)
        +Fixed(const int)
        +Fixed(const float)
        +~Fixed()
        +operator=(const Fixed&)
        +getRawBits() const
        +setRawBits(const int)
        +toFloat() const
        +toInt() const
    }

    class ostream {
        +<< (output_stream: std::ostream&, fixed_number: Fixed const&) : std::ostream&
    }

```

### fluxograma:
```mermaid
flowchart TD

    subgraph Fixed
        start -->|Default Constructor called| Initialize__rawBits=0
        start -->|Copy constructor called| Copy
        start -->|Destructor called| Clean
        start -->|Copy assignment operator called| Assign
        start -->|getRawBits member function called| Return
        start -->|setRawBits| Set
    end

```
