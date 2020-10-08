# Development requirements

## New classes

The main idea is to create a uniform structure for each class.

```cpp
namespace neno
{
    class [class-name]
    {
        public:
            [class-name](const char* path); //In constructor, we should load data, initialize buffers, engines etc.

            void [action](parameters); //In action method, we should use data or buffers. Name must be simple, for example 'Draw', 'Process', 'Play'. See for example Texture::Draw method.
    }
}
```

## Naming conventions
- Fields must be started with lower letter
- Methods must be started with upper letter(like in C#)
- Method parameters must be started with lower
- Variables in methods can be started with underscore '_'
- We should avoid using an underscore in variable, method or field names (for example, we should use textureId instead of texture_id). Does not apply to the previous point