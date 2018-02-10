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
    bool check;
    CRectangle rect[10];


    // メインループ
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {


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

            for (i = 0; i < 10; i++) {
                check = rect[i].check(x1, y1, x2, y2);
                if (check == false) {
                    flag = 1;
                }
                else { flag = 0; }
            }
        }//ドラッグ中
        if (check == false) {

            if (flag == 1) {
                x2 = mx;
                y2 = my;

                DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), 0);//四角形の描画
            }

            //ドラッグを終えたとき
            if ((mouse & MOUSE_INPUT_LEFT) == 0) {
                flag = 0;
                if (rect[i].flag == false) {
                    rect[i - 1].get_pos(x1, y1, x2, y2);
                }
            }
        }
            for (int j = 0; j <= 10; j++) {
                if (rect[j].flag == true) {
                    rect[j].show();
                }

            }
        }
    



    DxLib_End(); // DXライブラリ終了処理
    return 0;
}