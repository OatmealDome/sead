#pragma once

#include "hostio/seadHostIONode.h"
#include "math/seadVector.h"

namespace sead {

class Heap;

namespace hostio {
class Context;
}

namespace kcol {

struct KCollisionPrismData {
    f32 height;
    u16 position_index;
    u16 normal_a_index;
    u16 normal_b_index;
    u16 normal_c_index;
    u16 normal_d_index;
    u16 attribute;
};

struct KCollisionPrism {
    const Vector3f* positions;
    const Vector3f* normals;
    const void* _10;
    const void* _18;
    const KCollisionPrismData* data;
};

struct KCollisionPrismIndex {
    const u16* indices;
    KCollisionPrism prism;
};

struct KCollisionVersionData {
    u8 _0[0x38];
    f32 ray_step;
};

static_assert(offsetof(KCollisionPrismData, height) == 0x0);
static_assert(offsetof(KCollisionPrismData, position_index) == 0x4);
static_assert(offsetof(KCollisionPrismData, normal_d_index) == 0xc);
static_assert(offsetof(KCollisionPrismData, attribute) == 0xe);
static_assert(sizeof(KCollisionPrismData) == 0x10);
static_assert(offsetof(KCollisionPrism, positions) == 0x0);
static_assert(offsetof(KCollisionPrism, normals) == 0x8);
static_assert(offsetof(KCollisionPrism, data) == 0x20);
static_assert(sizeof(KCollisionPrism) == 0x28);
static_assert(offsetof(KCollisionPrismIndex, prism) == 0x8);
static_assert(sizeof(KCollisionPrismIndex) == 0x30);

class KCollision : public hostio::Node {
public:
    void create(const void* data, Heap* heap);
    void genMessage(hostio::Context* context);
    bool preCheckPoint(KCollisionPrismIndex* index, const Vector3f& point) const;
    f32 getRayStep() const { return (**mVersionData)->ray_step; }

protected:
    const void* mData;
    const u32* mPrismOffsets;
    const u32* mBlockData;
    u32 mBlockMaskX;
    u32 mBlockMaskY;
    u32 mBlockMaskZ;
    u32 mCoordMaskX;
    u32 mCoordMaskY;
    u32 mCoordMaskZ;
    KCollisionVersionData*** mVersionData; // TODO: what
};

static_assert(sizeof(KCollision) == 0x40);

}  // namespace kcol

}  // namespace sead
