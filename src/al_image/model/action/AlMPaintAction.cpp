/*
* Copyright (c) 2018-present, aliminabc@gmail.com.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
*/

#include "AlMPaintAction.h"
#include "Logcat.h"

#define TAG "AlMMosaicAction"

AlMPaintAction::AlMPaintAction() : AlAbsMFilterAction(TYPE_MOSAIC) {
    newPath();
}

AlMPaintAction::~AlMPaintAction() {
    path.clear();
};

void AlMPaintAction::newPath() {
    path.emplace_back(new AlPointPath());
}

void AlMPaintAction::paint(const AlVec2 &pointF) {
    if (!path.empty()) {
        path[path.size() - 1]->paintTo(pointF);
    }
    Logcat::i(TAG, "%s(%d) addPoint %d", __FUNCTION__, __LINE__, path.size());
}

HwResult AlMPaintAction::draw(HwAbsTexture *src, HwAbsTexture *dest) {
    return Hw::SUCCESS;
}

void AlMPaintAction::getPath(std::vector<float> &path) {
    for (AlPointPath *p:this->path) {
        auto *temp = p->path();
        for (float it:*temp) {
            path.emplace_back(it);
        }
    }
}

void AlMPaintAction::setPaintSize(float size) {
    this->paintSize = size;
}

float AlMPaintAction::getPaintSize() {
    return paintSize;
}

void AlMPaintAction::setColor(AlColor color) {
    this->color = color;
}

AlColor AlMPaintAction::getColor() {
    return color;
}

HwResult AlMPaintAction::fromElement(AlElement *element) {
    return Hw::SUCCESS;
}

HwResult AlMPaintAction::toElement(AlElement **element) {
    return Hw::SUCCESS;
}