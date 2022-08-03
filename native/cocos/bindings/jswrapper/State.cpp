/****************************************************************************
 Copyright (c) 2016 Chukong Technologies Inc.
 Copyright (c) 2017-2022 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
****************************************************************************/

#include "State.h"
#include "Object.h"

namespace se {

State::State(Object *thisObject)
: _thisObject(thisObject) {
    if (_thisObject != nullptr) {
        _thisObject->incRef();
    }
}

State::State(Object *thisObject, const ValueArray &args)
: _thisObject(thisObject),
  _args(&args) {
    if (_thisObject != nullptr) {
        _thisObject->incRef();
    }
}

State::~State() {
    SAFE_DEC_REF(_thisObject);
}

void *State::nativeThisObject() const {
    return _thisObject != nullptr ? _thisObject->getPrivateData() : nullptr;
}

Object *State::thisObject() {
    // _nativeThisObject in Static method will be nullptr
    //        assert(_thisObject != nullptr);
    return _thisObject;
}

const ValueArray &State::args() const {
    if (_args != nullptr) {
        return *(_args);
    }
    return EmptyValueArray;
}

Value &State::rval() {
    return _retVal;
}
} // namespace se