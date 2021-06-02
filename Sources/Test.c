#include <Vector3d.h>

int is_equal_double(Vertex *a, Vertex *b)
{
    if (fabs(gd(a, x) - gd(b, x)) < 0.001 && fabs(gd(a, y) - gd(b, y)) < 0.001 && fabs(gd(a, z) - gd(b, z)) < 0.001)
        return 1;
    else
        return 0;
}

int is_equal_complex(Vertex *a, Vertex *b)
{
    if (cabs(gc(a, x) - gc(b, x)) < 0.001 && cabs(gc(a, y) - gc(b, y)) < 0.001 && cabs(gc(a, z) - gc(b, z)) < 0.001)
        return 1;
    else
        return 0;
}

void test()
{
    Vertex *vec_Complex_first = create_Complex();
    Vertex *vec_double_first = create_double();
    Vertex *vec_Complex_second = create_Complex();
    Vertex *vec_double_second = create_double();

    Vertex *sumComplex = create_Complex();// полученные в программе значения
    Vertex *crossComplex = create_Complex();
    Vertex *sumComplex_t = create_Complex();// теоретические
    Vertex *diffComplex_t = create_Complex();
    Vertex *dotComplex_t = create_Complex();
    Vertex *divideComplex_t = create_Complex();
    Vertex *crossComplex_t = create_Complex();

    Vertex *sumDouble = create_double();// полученные в программе значения
    Vertex *crossDouble = create_double();
    Vertex *sumDouble_t = create_double();// теоретические
    Vertex *diffDouble_t = create_double();
    Vertex *dotDouble_t = create_double();
    Vertex *divideDouble_t = create_double();
    Vertex *crossDouble_t = create_double();

    double scalarDouble, scalarDouble_t, modDouble_t, modComplex_t;// полученные в программе значения, теоретические
    double complex scalarComplex, scalarComplex_t;
    double a, b;
    FILE *k = fopen("C:\\Laba1\\Data.txt", "r");
    if (k == NULL)
        printf("ERROR");
    // ввод всех теоретических значений из файла
    // ввод первого вектора
    fscanf(k, "%lf%lf%lf", &gd(vec_double_first, x), &gd(vec_double_first, y), &gd(vec_double_first, z));
    // ввод второго вектора
    fscanf(k, "%lf%lf%lf", &gd(vec_double_second, x), &gd(vec_double_second, y), &gd(vec_double_second, z));
    // ввод ответа для их суммы
    fscanf(k, "%lf%lf%lf", &gd(sumDouble_t, x), &gd(sumDouble_t, y), &gd(sumDouble_t, z));
    // ввод ответа для их разности
    fscanf(k, "%lf%lf%lf", &gd(diffDouble_t, x), &gd(diffDouble_t, y), &gd(diffDouble_t, z));
    // ввод ответа для их векторного произведения
    fscanf(k, "%lf%lf%lf", &gd(crossDouble_t, x), &gd(crossDouble_t, y), &gd(crossDouble_t, z));
    // ввод ответа для умножения на число
    fscanf(k, "%lf%lf%lf", &gd(dotDouble_t, x), &gd(dotDouble_t, y), &gd(dotDouble_t, z));
    // ввод ответа для деления на число
    fscanf(k, "%lf%lf%lf", &gd(divideDouble_t, x), &gd(divideDouble_t, y), &gd(divideDouble_t, z));
    // ввод ответа для их скалярного произведения
    fscanf(k, "%lf", &scalarDouble_t);
    // ввод ответа для модуля первого вектора
    fscanf(k, "%lf", &modDouble_t);

    // ввод первого вектора
    //scan_c(vec_Complex_first);
    fscanf(k, "%lf%lf", &a, &b);
    gc(vec_Complex_first, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(vec_Complex_first, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(vec_Complex_first, z) = a + b * I;

    // ввод второго вектора
    fscanf(k, "%lf%lf", &a, &b);
    gc(vec_Complex_second, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(vec_Complex_second, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(vec_Complex_second, z) = a + b * I;

    // ввод ответа для их суммы
    fscanf(k, "%lf%lf", &a, &b);
    gc(sumComplex_t, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(sumComplex_t, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(sumComplex_t, z) = a + b * I;

    // ввод ответа для их разности
    fscanf(k, "%lf%lf", &a, &b);
    gc(diffComplex_t, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(diffComplex_t, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(diffComplex_t, z) = a + b * I;

    // ввод ответа для их векторного произведения
    fscanf(k, "%lf%lf", &a, &b);
    gc(crossComplex_t, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(crossComplex_t, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(crossComplex_t, z) = a + b * I;

    // ввод ответа для умножения на число
    fscanf(k, "%lf%lf", &a, &b);
    gc(dotComplex_t, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(dotComplex_t, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(dotComplex_t, z) = a + b * I;

    // ввод ответа для деления на число
    fscanf(k, "%lf%lf", &a, &b);
    gc(divideComplex_t, x) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(divideComplex_t, y) = a + b * I;
    fscanf(k, "%lf%lf", &a, &b);
    gc(divideComplex_t, z) = a + b * I;

    // ввод ответа для их скалярного произведения
    fscanf(k, "%lf%lf", &a, &b);
    scalarComplex_t = a + b * I;

    // ввод ответа для модуля первого вектора
    fscanf(k, "%lf", &modComplex_t);
    fclose(k);

    sumDouble = sum_double(vec_double_first, vec_double_second);
    scalarDouble = scalar_double(vec_double_first, vec_double_second);
    crossDouble = cross_double(vec_double_first, vec_double_second);

    sumComplex = sum_Complex(vec_Complex_first, vec_Complex_second);
    scalarComplex = scalar_Complex(vec_Complex_first, vec_Complex_second);
    crossComplex = cross_Complex(vec_Complex_first, vec_Complex_second);

    int ans_double = is_equal_double(sumDouble, sumDouble_t);
    ans_double += is_equal_double(diff_double(vec_double_first, vec_double_second), diffDouble_t);
    ans_double += fabs(scalarDouble - scalarDouble_t) < 0.001;
    ans_double += is_equal_double(crossDouble, crossDouble_t);
    ans_double += is_equal_double(dotDouble_t, dot_double(vec_double_first, 2));
    ans_double += is_equal_double(divideDouble_t, divide_double(vec_double_first, 2));
    ans_double += fabs(modDouble_t - mod_double(vec_double_first)) < 0.001;
    if (ans_double == 7)
        printf("There aren't any errors in double values\n\n");
    else
        printf("ERROR\n\n");
    int ans_complex = is_equal_complex(sumComplex, sumComplex_t);
    ans_complex += is_equal_complex(diffComplex_t, diff_Complex(vec_Complex_first, vec_Complex_second));
    ans_complex += cabs(scalarComplex - scalarComplex_t) < 0.001;
    ans_complex += is_equal_complex(crossComplex, crossComplex_t);
    ans_complex += is_equal_complex(dotComplex_t, dot_Complex(vec_Complex_first, 2));
    ans_complex += is_equal_complex(divideComplex_t, divide_Complex(vec_Complex_first, 2));
    ans_complex += fabs(modComplex_t - mod_Complex(vec_Complex_first)) < 0.001;
    if (ans_complex == 7)
        printf("There aren't any errors in complex values\n");
    else
        printf("ERROR\n");
}

