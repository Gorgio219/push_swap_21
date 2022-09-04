Правила:
У вас есть 2 стопки с именами a и b.

В начале:
-Стопка a содержит случайное количество отрицательных и/или положительных чисел.
которые не могут быть продублированы.
-Стопка b пуста.
-Задача состоит в том, чтобы отсортировать в порядке возрастания числа в стеке a. 

Для этого в вашем распоряжении есть
в вашем распоряжении следующие операции:

```sa``` (swap a): Поменять местами первые 2 элемента на вершине стека a. Ничего не делать, если там только один или ни одного элемента.

```sb``` (swap b): Поменять местами первые 2 элемента на вершине стека b. Ничего не делать, если там только один или нет элементов.

```ss``` : sa и sb одновременно.

```pa``` (push a): Взять первый элемент на вершине b и поместить его на вершину a. Ничего не делать, если b пуст.

```pb``` (push b): Возьмите первый элемент в вершине a и поместите его в вершину b. Ничего не делать, если a пусто.

```ra``` (rotate a): Сдвинуть вверх все элементы стека a на 1. Первый элемент становится последним.

```rb``` (rotate b): Сдвинуть вверх все элементы стека b на 1. Первый элемент становится последним.

```rr``` : ra и rb одновременно.

```rra``` (reverse rotate a): Сдвинуть вниз все элементы стека a на 1. Последний элемент становится первым.

```rrb``` (reverse rotate b): Сдвинуть вниз все элементы стека b на 1. Последний элемент становится первым.

```rrr``` : rra и rrb одновременно.
