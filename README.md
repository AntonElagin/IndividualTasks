# IndividualTasks2
[![CircleCI](https://circleci.com/gh/AntonElagin/IndividualTasks/tree/Task2.svg?style=svg)](https://circleci.com/gh/AntonElagin/IndividualTasks/tree/Task2)

В вашем распоряжении — массив из 10 млн. структур,
содержащих числовой идентификатор записи (комментария) в социальной сети,
а также поля с семантикой средней оценки (целое 0 или вещественное от 1,0 до 5,0)
и числа поданных голосов (неотрицательное целое). Составьте наивный алгоритм подсчета
количества записей, не получивших ни единой оценки, а затем реализуйте параллельный
алгоритм с использованием нескольких процессов с учетом возможной реорганизации структуры 
и выравнивания ее элементов по линиям кэш-памяти.

<a href="https://72-213576085-gh.circle-artifacts.com/0/artifact-file"> Ссылка на gcovr </a> <br>

Result:<br>
<pre>    Array size : 10 000 000
    Parallel algorithm:
        Result = 1851533
        <b><i>Execution_time = 14361</i></b>
    Naive algorithm
        Result = 1851533
        <b><i>Execution_time = 45046</i></b>
</pre>
