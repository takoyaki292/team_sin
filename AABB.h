#pragma once
#include "Vector2.h"

struct AABB
{
    Vector2 min;
    Vector2 max;

    // AABB内に点が含まれているかの判定
    bool contains(const Vector2& point) const {
        return (point.x >= min.x && point.x <= max.x) &&
            (point.y >= min.y && point.y <= max.y);
    }

    // AABBが別のAABBに完全に含まれているかの判定
    bool contains(const AABB& other) const {
        return (other.min.x >= min.x && other.max.x <= max.x) &&
            (other.min.y >= min.y && other.max.y <= max.y);
    }

    // AABBの中心を取得
    Vector2 getCenter() const {
        return Vector2((min.x + max.x) / 2.0f,
            (min.y + max.y) / 2.0f);
    }

    // AABBのサイズを取得
    Vector2 getSize() const {
        return Vector2(max.x - min.x, max.y - min.y);
    }

    // AABBが他のAABBと衝突しているかの判定
    bool isColliding(const AABB& other) const {
        // X軸での重なりをチェック
        if (max.x < other.min.x || min.x > other.max.x) {
            return false;
        }

        // Y軸での重なりをチェック
        if (max.y < other.min.y || min.y > other.max.y) {
            return false;
        }

        // すべての軸で重なっていれば衝突している
        return true;
    }
};
