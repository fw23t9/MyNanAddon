#include <iostream>
#include <string>

#include <node.h>
#include <nan.h>

NAN_METHOD(say)
{
    info.GetReturnValue().Set(Nan::New<v8::String>(std::string("hello, world!")).ToLocalChecked());
}

NAN_MODULE_INIT(InitHello)
{
    try
    {
        NAN_EXPORT(target, say);
    }
    catch (std::exception e)
    {
        std::cout << e.what();
    }
}

NODE_MODULE(hello, InitHello)

