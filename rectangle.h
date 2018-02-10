#pragma once
#include "DxLib.h"

class CRectangle {
public:
    bool flag;
    CRectangle();
   void get_pos(int x1, int y1, int x2,int y2);
   void show();
   bool check(int x1, int y1, int x2, int y2);
private:
    int x1, y1, x2, y2;
   
   
};

CRectangle::CRectangle() {
    x1 = -1;
    y1 = -1;
    x2 = -1;
    y2 = -1;
    flag = false;
}
void CRectangle::get_pos(int x1, int y1, int x2, int y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->flag = true;
}
void CRectangle::show() {
    if (flag) {
        DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), 0);//lŠpŒ`‚Ì•`‰æ
    }

}

bool CRectangle::check(int x1, int y1, int x2, int y2) {    //‘I‘ğ
    if (this->x1 <= x1 && this->y1 <= y1 && this->x2 >= x2 && this->y2 >= y2) {
        return true;
    }
    else {
        return false;
    }
}



