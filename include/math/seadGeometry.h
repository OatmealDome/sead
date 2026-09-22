#pragma once

#include "math/seadVector.h"

namespace sead {

template <typename T>
struct Segment {
    T start;
    T end;
};

namespace Geometry {

f32 calcSquaredDistanceSegmentToSegment(const Segment<Vector3f>& first,
                                        const Segment<Vector3f>& second, f32* first_t,
                                        f32* second_t);

}  // namespace Geometry

}  // namespace sead
