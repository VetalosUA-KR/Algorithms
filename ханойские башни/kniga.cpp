Program Hanoi4;
Const maxN=...;
Var OpNum:Array[0..maxN] Of Longint;
{
    В элемент массива OpNum[i] записывается
    оптимальное количество перемещений
    при переносе i дисков
}
OpPar:
Array[0..maxN] Of Byte;
{
    В элемент массива OpPar[i] записывается
    оптимальный параметр, указывающий, какое
    количество дисков оставить на стержне
    при переносе i дисков
}
n,p1,p2,p3,p4:Byte;
Procedure Optimum;
{
    Определяет оптимальное значение параметра
    и наименьшее количество перекладываний
    для всех башен с высотами от 1 до n
}
Var i, j:
Byte;
Num:
Longint;
                                        2.10. Башни на четырех и более стержнях 211
Begin
OpPar[0]:=0;
OpNum[0]:=0;
{
    При нулевом количестве дисков значения,
    очевидно, нулевые
}
For i:=1 To n Do Begin
{
    Последовательно определяем оптимальные
    параметр и количество перекладываний для
    каждой задачи, используя подсчитанные
    значения для задач меньшей размерности}
OpPar[i]:=1;
OpNum[i]:=1 Shl i-1;
{
    Начальные значения соответствуют
    классическому алгоритму
}
For j:=2 To i-1 Do Begin
{
    Перебираем другие возможные значения
    параметра и находим значение, дающее
    минимальное количество перекладываний}
Num:=2*OpNum[i-j]+1 Shl j-1;
If Num<OpNum[i] Then Begin
OpPar[i]:=j;
OpNum[i]:=Num;
End;
End;
End;
End;
Procedure Hanoi3Pegs(n, p1, p2, p3:Byte);
{
    Переносит башню из n дисков со стержня p1 на p3,
    используя p2 как вспомогательный
}
Begin
If n>0 Then Begin
Hanoi3Pegs(n-1,p1,p3,p2);
WriteLn(’переносим диск со стержня ’,p1,’ на стержень ’,p3);
Hanoi3Pegs(n-1,p2,p1,p3);
End;
End;
Procedure Hanoi4Pegs(n, p1, p2, p3, p4: Byte);
{
    Переносит башню из n дисков p1 на p4,
    используя p2 и p3 как вспомогательные
}
                                            212 Глава 2. Вариации на тему о Ханойских башнях
Begin
If n>0 Then Begin
Hanoi4Pegs(n-OpPar[n], p1, p2, p4, p3);
Hanoi3Pegs(OpPar[n], p1, p2, p4);
Hanoi4Pegs(n-OpPar[n], p3, p2, p1, p4);
End;
End;
Begin
ReadLn(n,p1,p2,p3,p4);
Optimum;
Hanoi4Pegs(n,p1,p2,p3,p4);
End.
