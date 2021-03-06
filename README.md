# ClassFactory

1. About
2. Requirements
3. Instructions
4. Usage

##1. About
This library provides an easy to use interface in order to create class objects during runtime by simply passing a string which is assigned as a classname beforehand.  
Now you may ask yourself how this could come in handy. Well, here are some reasons to use this library:  
- You can pass requested objects from external resources (files, databases, ...) directly to an interface which will build the objects, no need for bloating your code with `if/else` statements
- Using this library is ridiculously easy. You need a total of `2` lines of code to add classes to the factory and `1 ` line is enough to construct objects from it.
- The library does not have any dependencies. Your compiler only has to support C++11
- Since you are using C++ you are obviously the master race in terms of programming languages. You are laughing about these dirty peasents which are using languages like Java. But then you realize, these dirty peasents have class reflection to work with and you don't. Well, this library does not add it to C++, but at least it enables you to create objects by their class names, which is a cool part of the class reflection

##2. Requirements
- C++11 compatible compiler
- CMake with version ≥ 2.8.12

##3. Instructions

- Download the source (via zip or by cloning this repo)
- Create a directory in which the build-files will be placed
- Run CMake for a compiler of your choice. If you wish you can enable the compilation of the example-project
- Compile with your chosen compiler
- The static library (and the example if enabled) will be placed under `YOUR_BUILD_DIR/bin/`
- To use the library in your projects, link against this library and add `LIBRARY_SOURCE_DIR/include/` to your include path or add the header files directly to your project

##4. Usage
Everything you need you will find in the header file `LCF.h`  
If you want to build an object of a simple single class (e.g. Superclass), you have to use following definitions:  
`FACTORY_REGISTER_SUPER_CLASS(Super)` inside your class and  
`FACTORY_FINISH_SUPER_REGISTRATION(Super, Name)` outside of your class  
If you have a bit more complex class-hierarchy (using derivations), you have to add a typedef inside your superclass:  
`typdef MySuperClass Super;` is what you need to add (in the protected scope of the class) in order to ensure that following definitions will work properly:  
`FACTORY_REGISTER_DERIVATED_CLASS(Derivated)` inside of your derivated class  
`FACTORY_FINISH_DERIVATED_REGISTRATION(Derivated, Name)` outside of your derivated class  
From now on, you can build your specified classes with calling `sClassFactory->Alloc<Super>(Name);`  
This will return an `std::unique_ptr<Super>` which points to the object specified by `Name`  
**Objects of derivated classes will be casted to their respective superclasses!**
  
Some Notes:  
- `Name` (above) means nothing else than a string with which you can access your registrated classes
- The registrations are **not** mutually exclusive, means you can register both Super and Derivated-Class(es)
- An empty pointer is returned if you:
 - Allocated a class object with an unknown name or which is not registered
 - Allocated a class object and requesting T as superclass when in reality the superclass of the target object is U
- So to make sure that you pointer is valid, just quickly check it with `if(your_pointer)`
- Make sure that you don't register an abstract class (a class which does not implement at least one pure virtual function), else you would imply that this class can be instantiated which is, of course, not true and will result in an error during compiling
- You can find an [example in the source](https://github.com/XaTToN/ClassFactory/blob/master/src/example/main.cpp)
