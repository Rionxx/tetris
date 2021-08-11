#ifndef _TETRIS_H_
#define _TETRIS_H_

//�@�����u���b�N�̐ݒ�
#define INITX
#define FALL_LOOP_NUM 13

// �u���b�N��ǂ̒u������
#define BLOCK_WHEN_FALLING 1
#define BLOCK_AFTER_LANDING 2
#define BLOCK_ON_BLOCK	BLOCK_WHEN_FALLING + BLOCK_AFTER_LANDING
#define FIELD_WALL 4
#define BLOCK_ON_FIELD_WALL 5
#define BLOCK_OVERLAP_WITH_BLOCK  BLOCK_WHEN_FALLING + BLOCK_AFTER_LANDING
#define BLOCK_OVERLAP_WITH_FIELD  BLOCK_WHEN_FALLING + FIELD_WALL

//�t�B�[���h����уu���b�N�̎w��
#define F_WIDTH  12               // �t�B�[���h�̕�
#define F_HEIGHT 21               // �t�B�[���h�̍���
#define F_NUM  F_WIDTH * F_HEIGHT // �t�B�[���h�̃}�X�̐�
#define NO_WALL_NUM  (F_WIDTH - 2) * (F_HEIGHT - 1) //���E���̕ǂ����������̃t�B�[���h�̃}�X�̐�
#define B_WIDTH  4                // �u���b�N�̕�
#define B_HEIGHT 4                // �u���b�N�̍���
#define B_NUM  B_WIDTH * B_HEIGHT // �u���b�N�̃}�X�̐�

// �L�[�{�[�h�̓���
#define BUTTON_ARROW  224 // �����ꂩ�̖��L�[  
#define BUTTON_LEFT    75 // ���F�u���b�N�����Ɉړ�������
#define BUTTON_RIGHT   77 // ���F�u���b�N���E�Ɉړ�������
#define BUTTON_UP      72 // ���F�u���b�N����C�ɗ���������
#define BUTTON_DOWN    80 // ���F�u���b�N�̗�����X�s�[�h������������
#define PIVOT_CW      120 // X �F�u���b�N�����v���ɉ�]������
#define PIVOT_CCW     122 // Z �F�u���b�N���t���v���ɉ�]������

//���ꂼ��̃u���b�N�̌`
#define STICK   0
#define SQUARE  1
#define MOUNT   2
#define LWORD1  3
#define LWORD2  4
#define TWIST1  5
#define TWIST2  6

//�֐��|�C���^�p�v���v���Z�b�T(�����F�Ȃ��@�߂�l�F�Ȃ�)
#define MAKE_WALL           0
#define BLOCK_PLUS_FIELD    1
#define DRAW_FIELD          2
#define INIT_FIELD          3
#define SAVE_FIELD          4
#define STOP_BLOCK          5
#define ERASE_BLOCK         6
#define CONTROL_BLOCK       7
#define FALL_BLOCK_AT_ONCE  8
#define FINISH_GAME         9

//�v���g�^�C�v�i�����Ȃ��A�߂�l�Ȃ��j
void make_wall(void);          // �t�B�[���h�̕ǂ𐶐�
void block_plus_field(void);   // �t�B�[���h�ƃu���b�N�𑫂����킹��
void draw_field(void);         // �t�B�[���h��̕ǂ�u���b�N��F�����₷���L���ɒu��
void init_field(void);         // �t�B�[���h��������
void save_field(void);         // �t�B�[���h�̏�Ԃ�ۑ�
void stop_block(void);         // ���n�����u���b�N�̓������~�߂�
void erase_block(void);        // �u���b�N�Ŗ��܂����s���폜����
void control_block(void);      // �u���b�N�𑀍삷��i���E�㉺�A��]�j
void fall_block_at_once(void); // �u���b�N����C�ɉ��ɗ���������
void finish_game(void);        // �Q�[�����I��������

//�v���g�^�C�v�i���̑��j
void fill_erased_row(int rownum);                // �u���b�N�������ɑS�ċ󗓂̍s���ł����ꍇ�A���ɋl�߂�
void slide_block(char* direction);               // �u���b�N�����E�Ɉړ�������
void roll(struct BLOCK* hblock, int direction);  // �u���b�N����]������
char* get_field_state_when_slide(int direction); // �u���b�N�����E�Ɉړ����������̎��͂̏�Ԃ��擾
char* get_field_state_when_roll(void);           // �u���b�N����]���������̎��͂̏�Ԃ��擾
char* get_block_landing_state(void);             // �u���b�N�����n�������ǂ������m�F
int get_row_sum(int height);


struct BLOCK {
	int num;
	char* name;
	int shape[4][4];
};

#endif // !_TETRIS_H_
