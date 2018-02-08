#include "DxLib.h"
#include "rectangle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(true);         // �E�B���h�E���[�h(false:�t���X�N���[��)

    SetGraphMode(640, 480, 16);

    DxLib_Init();                   // DX���C�u��������������
    SetDrawScreen(DX_SCREEN_BACK);  // ����ʐݒ�

    int x1=-1, y1=-1, x2 = -1, y2 = -1; //�g���W
    int flag=0; 
    int mx=0, my=0;   //�}�E�X���W
    int mouse;      //�}�E�X�̏��
    int i=0;  //�z��NO.
    int no=10;

    CRectangle rect[10];


    // ���C�����[�v
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 ){


        // �}�E�X��\����Ԃɂ���
        SetMouseDispFlag(1);

        //�}�E�X�̈ʒu�擾
        GetMousePoint(&mx, &my);

        mouse = GetMouseInput();

        //���N���b�N����Ă��邩
        if ((mouse & MOUSE_INPUT_LEFT) != 0 && flag == 0) {
            x1 = mx;
            y1 = my;
            x2 = mx;
            y2 = my;
            flag++;
            if (i < no) { i++; }
        }//�h���b�O��
        if (flag == 1) {
            x2 = mx;
            y2 = my;

            DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), 0);//�l�p�`�̕`��
        }

        //�h���b�O���I�����Ƃ�
        if ((mouse & MOUSE_INPUT_LEFT) == 0 ){
            flag = 0;
            rect[i-1].get_pos(x1, y1, x2, y2);
           
        }
        for (int j = 0; j <= i; j++) {
            rect[j].show();
        }
        //DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), 0);//�l�p�`�̕`��

    // DrawFormatString(0, 0, GetColor(255, 255, 255), "[%d,%d,%d,%d]", x1, y1, x2, y2);
    //DrawFormatString(0, 20, GetColor(255, 255, 255), "[%d,%d]", mx, my);
    }

    DxLib_End(); // DX���C�u�����I������
    return 0;
}