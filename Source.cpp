#include "DxLib.h"
#include "rectangle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(true);         // ウィンドウモード(false:フルスクリーン)

    SetGraphMode(640, 480, 16);

    DxLib_Init();                   // DXライブラリ初期化処理
    SetDrawScreen(DX_SCREEN_BACK);  // 裏画面設定

    int x1=-1, y1=-1, x2 = -1, y2 = -1; //枠座標
    int flag=0; 
    int mx=0, my=0;   //マウス座標
    int mouse;      //マウスの状態
    int i=0;  //配列NO.
    int no=10;

    CRectangle rect[10];


    // メインループ
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 ){


        // マウスを表示状態にする
        SetMouseDispFlag(1);

        //マウスの位置取得
        GetMousePoint(&mx, &my);

        mouse = GetMouseInput();

        //左クリックされているか
        if ((mouse & MOUSE_INPUT_LEFT) != 0 && flag == 0) {
            x1 = mx;
            y1 = my;
            x2 = mx;
            y2 = my;
            flag++;
            if (i < no) { i++; }
        }//ドラッグ中
        if (flag == 1) {
            x2 = mx;
            y2 = my;

            DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), 0);//四角形の描画
        }

        //ドラッグを終えたとき
        if ((mouse & MOUSE_INPUT_LEFT) == 0 ){
            flag = 0;
            rect[i-1].get_pos(x1, y1, x2, y2);
           
        }
        for (int j = 0; j <= i; j++) {
            rect[j].show();
        }
        //DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), 0);//四角形の描画

    // DrawFormatString(0, 0, GetColor(255, 255, 255), "[%d,%d,%d,%d]", x1, y1, x2, y2);
    //DrawFormatString(0, 20, GetColor(255, 255, 255), "[%d,%d]", mx, my);
    }

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}