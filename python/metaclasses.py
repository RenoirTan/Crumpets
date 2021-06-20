import typing as t

class MetaClass(type):
    def __new__(
        cls,
        name: str,
        bases: t.Iterable[type],
        attributes: t.Dict[str, t.Any]
    ) -> type:
        print(f"Name of the new class: {name}")
        print(f"Parent classes:")
        for base in bases:
            print(f"\t- {base}")
        print(f"Attributes and methods:")
        for attr_name, attr_val in attributes.items():
            print(f"\t .{attr_name} : {attr_val}")
        new_class = super().__new__(cls, name, bases, attributes)
        new_class.say_hi = lambda self: print("Hi")
        return new_class


if __name__ == "__main__":
    class Foo(metaclass=MetaClass):
        static_attr = 5
        def method(self):
            return self.static_attr
    
    foo = Foo()
    foo.say_hi()
