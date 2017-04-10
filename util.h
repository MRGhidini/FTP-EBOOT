#define MAX_PICK 5
#define MAX_PICK_TITLE 80
#define MAX_PICK_MAINSTR 13
#define MAX_PICK_FINEPRINT 45

typedef struct
{
    char szBig[MAX_PICK_MAINSTR+1]; // fonte grande
    char szFinePrint[MAX_PICK_FINEPRINT+1]; // fonte pequena
    u32 userData;
} PICKER_INFO;

typedef struct
{
    char szTitle[MAX_PICK_TITLE+1];
    int pick_count;
    PICKER_INFO picks[MAX_PICK];
    int pick_start; // -1 vazio, 0->pick_count-1 selecionar
} PICKER;

int my_picker(const PICKER* pickerP);
    // returns new pick or -1 se cancelar

void my_initpicker(PICKER* pickerP, const char* szTitle);
bool my_addpick(PICKER* pickerP, const char* szBig, const char* szFinePrint, u32 userData);

int my_loadpicks_fromfile(PICKER* pickerP, const char* szFile, bool bParseIP);
    // retorna numero entrada lida

extern char *my_dirname(char *filename);
