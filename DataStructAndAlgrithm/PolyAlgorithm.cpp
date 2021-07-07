using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include "PolyAlgorithm.h"

/**
* @description ���߷��жϵ��Ƿ��ڶ�����ڲ�,���������ε��ཻ����Ϊ���������ڣ�Ϊż��������
* @param {Point} p ���жϵĵ㣬��ʽ��{ x: X����, y: Y���� }
* @param {vector<Point>} poly ����ζ��㣬�����Ա�ĸ�ʽͬ p
* @return {String} �� p �Ͷ���� poly �ļ��ι�ϵ
* https://blog.csdn.net/qq_27161673/article/details/52973866
*/
    string PolygonAlgorithm::rayCasting(Point p, vector<Point> poly) {
        int pointCnt = (int)poly.size();
        int count = 0;
        int i = 0;
        int j = 0;

        for (i = 0, j = pointCnt - 1; i < pointCnt; j=i,i++) {
            // 1.�������ζ����غ�
            if ((p.x == poly[i].x && p.y == poly[i].y)
                || (p.x == poly[j].x && p.y == poly[j].y))
            {
                count = 1;
                break;
            }

            //3.���������Ƕ���εı�ʱ����Ϊû�д�������ʱpoly[i].y == poly[j].y
            // �ж��߶����˵��Ƿ�����������
            if (p.y >= min(poly[i].y, poly[j].y) && p.y < max(poly[i].y, poly[j].y))
            {//4.���߾�������εĵ�ʱ���涨���߾����ĵ㶼�����������µ�һ��

                // �߶��������� Y ������ͬ�ĵ�� X ����
                double tempX = poly[i].x + (p.y - poly[i].y) * (poly[j].x - poly[i].x) / (poly[j].y - poly[i].y);
                // 2.���ڶ���εı���
                if (tempX == p.x)
                {
                    count = 1;
                    break;
                }

                // ���ߴ�������εı߽�
                if (tempX > p.x)
                {
                    count++;
                }
            }
        }

        // ���ߴ�������α߽�Ĵ���Ϊ����ʱ���ڶ������
        if (count % 2)
        {
            return "in";
        }
        else
        {
            return "out";
        }
    }