#include <stdio.h>
#include "StdTypes.h"

typedef struct MyStudent
{
    u32 id;
    u32 english;
    u32 math;
    f32 average;
} Student;

typedef struct 
{
    s32 x;
    s32 y;
} Complex;

typedef struct 
{
    u8 x : 1;
    u8 y : 2;
    u8 z : 4;
} MyStruct;

typedef enum 
{
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
} Day;

typedef enum {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
} Port;

typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
} Pin;

typedef enum
{
    LOW,
    HIGH
} Level;
typedef union 
{
    u8 x;
    u16 y;
    u32 z;
}MyUnion;

typedef union {
    struct
    {
        u8 B0 : 1;
        u8 B1 : 1;
        u8 B2 : 1;
        u8 B3 : 1;
        u8 B4 : 1;
        u8 B5 : 1;
        u8 B6 : 1;
        u8 B7 : 1;
    } Bit;
    u8 Byte;
} Register;

void SetPinLevel(Port port, Pin pin, Level level);
Complex addComplex (Complex n1, Complex n2);
Complex addComplexRef (const Complex* n1, const Complex* n2);
int main(void)
{
    /*
    struct MyStudent ahmed;
    ahmed.id = 5;
    ahmed.math = 60;
    ahmed.english = 50;
    ahmed.average = (ahmed.math + ahmed.english) / 2.0;
    printf("Ahmed id        = %d\n", ahmed.id     );
    printf("Ahmed math      = %d\n", ahmed.math   );
    printf("Ahmed english   = %d\n", ahmed.english);
    printf("Ahmed average   = %f\n", ahmed.average);
    */

   /*
    struct MyStudent ahmed = {0,0,0,0};
    struct MyStudent ali;
    printf("Enter Ahmed id     : ");
    scanf("%d", &ahmed.id);
    printf("Enter Ahmed math   : ");
    scanf("%d", &ahmed.math);
    printf("Enter Ahmed english: ");
    scanf("%d", &ahmed.english);
    ahmed.average = (ahmed.math + ahmed.english) / 2.0;
    printf("Enter Ali id     : ");
    scanf("%d", &ali.id);
    printf("Enter Ali math   : ");
    scanf("%d", &ali.math);
    printf("Enter Ali english: ");
    scanf("%d", &ali.english);
    ali.average = (ali.math + ali.english) / 2.0;
    printf("Ahmed Average = %f\n", ahmed.average);
    printf("Ali Average = %f\n", ali.average);
    if (ahmed.average > ali.average) {
        printf("Ahmed");
    }
    else if (ali.average > ahmed.average){
        printf ("Ali");
    }
    else {
        printf("Eqaul");
    }
*/
/*
    Student students[100];
    u32 i, n, min_index = 0, max_index = 0;
    f32 min, max;
    printf("Please enter students count: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter Student %d id: ", i+1);
        scanf("%d", &students[i].id);
        printf("Enter Student %d math: ", i+1);
        scanf("%d", &students[i].math);
        printf("Enter Student %d english: ", i+1);
        scanf("%d", &students[i].english);
        students[i].average = (students[i].math + students[i].english) / 2.0;
    }
    min = students[0].average;
    max = students[0].average;
    for (i=0; i<n; i++)
    {
        printf("Student %d average = %f\n",i+1, students[i].average);
        if (students[i].average > max)
        {
            max = students[i].average;
            max_index = i;
        }
        if (students[i].average < min)
        {
            min = students[i].average;
            min_index = i;
        }
    }
    printf("Max average = %f for student %d\n", max, max_index+1);
    printf("Min average = %f for student %d\n", min, min_index+1);
*/
/*
    Complex n1, n2, result;
    printf("Please enter first number: ");
    scanf("%d %d", &n1.x, &n1.y);
    printf("Please enter second number: ");
    scanf("%d %d", &n2.x, &n2.y);
    result = addComplex(n1, n2);
    printf("Result = %d%+di", result.x, result.y);
*/
    //printf("size = %d", sizeof(Student));
/*
    Student ahmed = {0,0,0,0};
    Student* ptr = &ahmed;
    (*ptr).id = 6;
    ptr->id = 5;
    printf("id = %d", (*ptr).id);
*/
/*
    Complex n1, n2, result;
    printf("Address of n1 = %p\n", &n1);
    printf("Address of n1.x = %p\n", &n1.x);
    printf("Address of n1.y = %p\n", &n1.y);
    
    printf("Please enter first number: ");
    scanf("%d %d", &n1.x, &n1.y);
    printf("Please enter second number: ");
    scanf("%d %d", &n2.x, &n2.y);
    result = addComplexRef(&n1, &n2);
    printf("Result = %d%+di", result.x, result.y);
*/
/*
    MyStruct m;
    m.z = 17;
    printf("%d", m.z);
*/
/*
    Day day = SUNDAY;
    printf("day = %d\n", day);
    printf("size of Day = %d\n", sizeof(Day));
    printf("size of day = %d\n", sizeof(day));
    if (day == MONDAY) {
        printf("TRUE");
    }
    //SetPinLevel(PORTA, PIN0, HIGH);
    //SetPinLevel(0, 0, 1);
    */
   /*
    MyUnion m;
    m.z = 0;
    printf("x = %x\n", m.x);
    printf("y = %x\n", m.y);
    printf("z = %x\n", m.z);
    m.z = 0xAABBCCDD;
    printf("x = %x\n", m.x);
    printf("y = %x\n", m.y);
    printf("z = %x\n", m.z);
    m.x = 0;
    printf("x = %x\n", m.x);
    printf("y = %x\n", m.y);
    printf("z = %x\n", m.z);
    m.y = 0;
    printf("x = %x\n", m.x);
    printf("y = %x\n", m.y);
    printf("z = %x\n", m.z);
    */

    Register x;
   x.Byte = 0;
   printf("%d\n", x.Byte);
   x.Bit.B2 = 1;
   x.Bit.B3 = 1;
   printf("%d\n", x.Byte);


}

Complex addComplex (Complex n1, Complex n2)
{
    Complex result;
    result.x = n1.x + n2.x;
    result.y = n1.y + n2.y;
    return result;
}

Complex addComplexRef (const Complex* n1, const Complex* n2)
{
    Complex result;
    result.x = n1->x + n2->x;
    result.y = n1->y + n2->y;
    return result;
}