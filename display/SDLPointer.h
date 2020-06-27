
#ifndef __sdl_pointer_h
#define __sdl_pointer_h

template<typename T>
using SDLPointerDestructor =
    std::function<void(T*)>;

template<typename T>
class SDLPointer {
    public:
        SDLPointer() : pointer{} { }
        SDLPointer(T* rawPointer, void (*)(T*));
        operator T*() const;

        T* get();

    private:
        SDLPointerDestructor<T> createSDLPointerLambdaDestructor(void (*)(T*));
        std::unique_ptr<T, SDLPointerDestructor<T>> pointer;
};

template<typename T>
SDLPointer<T>::SDLPointer(T* rawPointer, void (*destructor)(T*)) {
    auto sdlPointerLambdaDestructor = createSDLPointerLambdaDestructor(destructor);
    pointer = 
        std::unique_ptr<T, SDLPointerDestructor<T>>(rawPointer, sdlPointerLambdaDestructor);
}

template<typename T>
SDLPointer<T>::operator T*() const {
    return pointer.get();
}

template<typename T>
SDLPointerDestructor<T> SDLPointer<T>::createSDLPointerLambdaDestructor(void (*destructor)(T*)) {
    return [destructor](T *rawPointer) {
        (*destructor)(rawPointer);
    };
}

template<typename T>
T* SDLPointer<T>::get() { 
    return pointer.get();
}

#endif 