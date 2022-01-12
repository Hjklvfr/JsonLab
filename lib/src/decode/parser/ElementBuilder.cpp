#include "ElementBuilder.h"
#include "../../entities/JsonNumber.h"
#include "../../entities/JsonBool.h"
#include "../../entities/JsonNull.h"
#include "../../entities/JsonArray.h"
#include "../../_utils/ClassExtensions.h"

void ElementBuilder::onNumber(std::string value) {
    JsonNumber* number = new JsonNumber(value);
    if (root == nullptr) {
        root = number;
    } else {
        JsonValue* parent_value = getCurrent();
        JsonArray* parent_array = dynamic_cast<JsonArray*>(parent_value);
        if (parent_array != nullptr) {
            parent_array->add(number);
            return;
        }
    }
    branch.push_back(number);
}

void ElementBuilder::onString(std::string value) {
    JsonString* string = new JsonString(value);
    if (root == nullptr) {
        root = string;
    } else {
        JsonValue* parent_value = getCurrent();
        JsonArray* parent_array = dynamic_cast<JsonArray*>(parent_value);
        if (parent_array != nullptr) {
            parent_array->add(string);
            return;
        }
    }
    branch.push_back(string);
}

void ElementBuilder::onBool(bool value) {
    JsonBool* boolean = new JsonBool(value);
    if (root == nullptr) {
        root = boolean;
    } else {
        JsonValue* parent_value = getCurrent();
        JsonArray* parent_array = dynamic_cast<JsonArray*>(parent_value);
        if (parent_array != nullptr) {
            parent_array->add(boolean);
            return;
        }
    }
    branch.push_back(boolean);
}

void ElementBuilder::onNull() {
    JsonNull* null = new JsonNull();
    if (root == nullptr) {
        root = null;
    } else {
        JsonValue* parent_value = getCurrent();
        JsonArray* parent_array = dynamic_cast<JsonArray*>(parent_value);
        if (parent_array != nullptr) {
            parent_array->add(null);
            return;
        }
    }
    branch.push_back(null);
}

void ElementBuilder::onObjectStart() {
    JsonObject* object = new JsonObject();
    if (root == nullptr) {
        root = object;
    }
    branch.push_back(object);
}

void ElementBuilder::onObjectMemberStart() {
    JsonMember* member = new JsonMember();
    if (root == nullptr) {
        root = member;
    }
    branch.push_back(member);
}

void ElementBuilder::onObjectMemberEnd() {
    JsonValue* value = getCurrent();
    JsonValue* name_value = getCurrentsParent();

    JsonString* name = dynamic_cast<JsonString*>(name_value);
    if(name == nullptr) {
        return;
    }

    branch.pop_back();
    branch.pop_back();

    JsonValue* current = getCurrent();
    JsonMember* member = dynamic_cast<JsonMember*>(current);
    if (member == nullptr) {
        return; 
    }
    member->setName(name);
    member->setValue(value);

    JsonValue* parrent_of_current = getCurrentsParent();
    if (current != root) {
        JsonObject* parrent_object = dynamic_cast<JsonObject*>(parrent_of_current);
        if (parrent_object == nullptr) {
            return; 
        }
        parrent_object->addMember(member);
        branch.pop_back();
    } else {
    }
}

void ElementBuilder::onObjectEnd() {
    JsonValue* current_value = getCurrent();
    JsonValue* parent = getCurrentsParent();

    if (current_value == root) {
        branch.pop_back();
    }
    JsonArray* parent_array = dynamic_cast<JsonArray*>(parent);
    if (parent_array != nullptr) {
        parent_array->add(current_value);
        branch.pop_back();
        return;
    }
}

void ElementBuilder::onArrayStart() {
    JsonArray* array = new JsonArray();
    if (root == nullptr) {
        root = array;
    }
    branch.push_back(array);
}

void ElementBuilder::onArrayEnd() {
    JsonValue* current_value = getCurrent();
    JsonValue* parent = getCurrentsParent();

    if (current_value == root) {
        branch.pop_back();
    }
    JsonArray* parent_array = dynamic_cast<JsonArray*>(parent);
    if (parent_array != nullptr) {
        parent_array->add(current_value);
        branch.pop_back();
        return;
    }
}

JsonValue* ElementBuilder::getCurrent() const {
    if (!branch.empty())
        return branch[branch.size() - 1];
    else return nullptr;
}

JsonValue* ElementBuilder::getCurrentsParent() const {
    if (branch.size() > 1)
        return branch[branch.size() - 2];
    else return nullptr;
}

JsonValue* ElementBuilder::getRoot() const {
    return root;
}
