using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include "PolyAlgorithm.h"

/**
* @description 射线法判断点是否在多边形内部,射线与多边形的相交次数为奇数，则在，为偶数，则不在
* @param {Point} p 待判断的点，格式：{ x: X坐标, y: Y坐标 }
* @param {vector<Point>} poly 多边形顶点，数组成员的格式同 p
* @return {String} 点 p 和多边形 poly 的几何关系
* https://blog.csdn.net/qq_27161673/article/details/52973866
*/
    string PolygonAlgorithm::rayCasting(Point p, vector<Point> poly) {
        int pointCnt = (int)poly.size();
        int count = 0;
        int i = 0;
        int j = 0;

        for (i = 0, j = pointCnt - 1; i < pointCnt; j=i,i++) {
            // 1.点与多边形顶点重合
            if ((p.x == poly[i].x && p.y == poly[i].y)
                || (p.x == poly[j].x && p.y == poly[j].y))
            {
                count = 1;
                break;
            }

            //3.射线正好是多边形的边时，认为没有穿过，此时poly[i].y == poly[j].y
            // 判断线段两端点是否在射线两侧
            if (p.y >= min(poly[i].y, poly[j].y) && p.y < max(poly[i].y, poly[j].y))
            {//4.射线经过多边形的点时，规定射线经过的点都属于射线以下的一侧

                // 线段上与射线 Y 坐标相同的点的 X 坐标
                double tempX = poly[i].x + (p.y - poly[i].y) * (poly[j].x - poly[i].x) / (poly[j].y - poly[i].y);
                // 2.点在多边形的边上
                if (tempX == p.x)
                {
                    count = 1;
                    break;
                }

                // 射线穿过多边形的边界
                if (tempX > p.x)
                {
                    count++;
                }
            }
        }

        // 射线穿过多边形边界的次数为奇数时点在多边形内
        if (count % 2)
        {
            return "in";
        }
        else
        {
            return "out";
        }
    }