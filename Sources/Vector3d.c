#include <Vector3d.h>
#define Begin_Complex                                            \
    Vertex *vec = (Vertex *)malloc(sizeof(double _Complex) * 3); \
    (*vec).x = malloc(sizeof(double _Complex));                  \
    (*vec).y = malloc(sizeof(double _Complex));                  \
    (*vec).z = malloc(sizeof(double _Complex));                  \
    Vertex *V_a = (Vertex *)a;                                   \
    Vertex *V_b = (Vertex *)b

#define Begin_double                                    \
    Vertex *vec = (Vertex *)malloc(sizeof(double) * 3); \
    (*vec).x = malloc(sizeof(double));                  \
    (*vec).y = malloc(sizeof(double));                  \
    (*vec).z = malloc(sizeof(double));                  \
    Vertex *V_a = (Vertex *)a;                          \
    Vertex *V_b = (Vertex *)b

#define gc(V_a, x) *(double _Complex *)((*V_a).x)
#define gd(V_a, x) *(double *)((*V_a).x)
#define grc(V_a, x) *(_C_double_complex *)((*V_a).x)
Vertex *create_Complex()
{
    Vertex *vec = (Vertex *)malloc(sizeof(double _Complex) * 3);
    (*vec).x = malloc(sizeof(double _Complex));
    (*vec).y = malloc(sizeof(double _Complex));
    (*vec).z = malloc(sizeof(double _Complex));
    return vec;
}
Vertex *create_double()
{
    Vertex *vec = (Vertex *)malloc(sizeof(double) * 3);
    (*vec).x = malloc(sizeof(double));
    (*vec).y = malloc(sizeof(double));
    (*vec).z = malloc(sizeof(double));
    return vec;
}
/// сумма векторов
void *sum_Complex(void *a, void *b)
{
    Begin_Complex;
    *(double _Complex *)vec->x = (*(double _Complex *)((*V_a).x) + *(double _Complex *)((*V_b).x));
    *(double _Complex *)vec->y = (*(double _Complex *)((*V_a).y) + *(double _Complex *)((*V_b).y));
    *(double _Complex *)vec->z = (*(double _Complex *)((*V_a).z) + *(double _Complex *)((*V_b).z));
    return vec;
}
/// сумма векторов
void *sum_double(void *a, void *b)
{
    Begin_double;
    *(double *)vec->x = (*(double *)((*V_a).x) + *(double *)((*V_b).x));
    *(double *)vec->y = (*(double *)((*V_a).y) + *(double *)((*V_b).y));
    *(double *)vec->z = (*(double *)((*V_a).z) + *(double *)((*V_b).z));
    return vec;
}
/// разность векторов
void *diff_Complex(void *a, void *b)
{
    Begin_Complex;
    *(double _Complex *)vec->x = (*(double _Complex *)((*V_a).x) - *(double _Complex *)((*V_b).x));
    *(double _Complex *)vec->y = (*(double _Complex *)((*V_a).y) - *(double _Complex *)((*V_b).y));
    *(double _Complex *)vec->z = (*(double _Complex *)((*V_a).z) - *(double _Complex *)((*V_b).z));
    return vec;
}
/// разность векторов
void *diff_double(void *a, void *b)
{
    Begin_double;
    *(double *)vec->x = (*(double *)((*V_a).x) - *(double *)((*V_b).x));
    *(double *)vec->y = (*(double *)((*V_a).y) - *(double *)((*V_b).y));
    *(double *)vec->z = (*(double *)((*V_a).z) - *(double *)((*V_b).z));
    return vec;
}
/// скалярное произведение
void *scalar_Complex(void *a, void *b)
{
    Begin_Complex;
    double _Complex *res = (double _Complex *)malloc(sizeof(double _Complex));
    res[0] = gc(V_a, x) * gc(V_b, x) + gc(V_a, y) * gc(V_b, y) + gc(V_a, z) * gc(V_b, z);
    return res;
}
/// скалярное произведение
void *scalar_double(void *a, void *b)
{
    Begin_double;
    double *res = (double *)malloc(sizeof(double));
    res[0] = gd(V_a, x) * gd(V_b, x) + gd(V_a, y) * gd(V_b, y) + gd(V_a, z) * gd(V_b, z);
    return res;
}
/// модуль вектора
double *mod_Complex(void *a)
{
    Vertex *V_a = (Vertex *)a;
    double *res = (double *)malloc(sizeof(double));
    res[0] = sqrt(cabs(gc(V_a, x)) * cabs(gc(V_a, x)) + cabs(gc(V_a, y)) * cabs(gc(V_a, y)) + cabs(gc(V_a, z)) * cabs(gc(V_a, z)));
    return res;
    //https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/complex-math-support?view=msvc-160
}
/// модуль вектора
double *mod_double(void *a)
{
    Vertex *V_a = (Vertex *)a;
    double *res = (double *)malloc(sizeof(double));
    res[0] = sqrt(gd(V_a, x) * gd(V_a, x) + gd(V_a, y) * gd(V_a, y) + gd(V_a, z) * gd(V_a, z));
    return res;
}
/// делает вектор единичным
void *normalize_Complex(void *a)
{
    double len = *mod_Complex(a);
    Vertex *V_a = (Vertex *)a;
    if (len > 0.0)
    {
        gc(V_a, x) /= len;
        gc(V_a, y) /= len;
        gc(V_a, z) /= len;
    }
    return a;
}
/// делает вектор единичным
void *normalize_double(void *a)
{
    double len = *mod_double(a);
    Vertex *V_a = (Vertex *)a;
    if (len > 0.0)
    {
        gd(V_a, x) /= len;
        gd(V_a, y) /= len;
        gd(V_a, z) /= len;
    }
    return a;
}
/// умножение вектора на число
void *dot_Complex(void *vec, double c)
{
    Vertex *V_vec = (Vertex *)vec;
    gc(V_vec, x) *= c;
    gc(V_vec, y) *= c;
    gc(V_vec, z) *= c;
    return V_vec;
}
/// умножение вектора на число
void *dot_double(void *vec, double c)
{
    Vertex *V_vec = (Vertex *)vec;
    gd(V_vec, x) *= c;
    gd(V_vec, y) *= c;
    gd(V_vec, z) *= c;
    return V_vec;
}
/// деление вектора на число
void *divide_Complex(void *vec, double c)
{
    Vertex *V_vec = (Vertex *)vec;
    gc(V_vec, x) /= c;
    gc(V_vec, y) /= c;
    gc(V_vec, z) /= c;
    return V_vec;
}
/// умножение вектора на число
void *divide_double(void *vec, double c)
{
    Vertex *V_vec = (Vertex *)vec;
    gd(V_vec, x) /= c;
    gd(V_vec, y) /= c;
    gd(V_vec, z) /= c;
    return V_vec;
}
/// разворот вектора
void *reverse_Complex(void *a)
{
    Vertex *V_a = (Vertex *)a;
    gc(V_a, x) = -gc(V_a, x);
    gc(V_a, y) = -gc(V_a, y);
    gc(V_a, z) = -gc(V_a, z);
    return V_a;
}
/// разворот вектора
void *reverse_double(void *a)
{
    Vertex *V_a = (Vertex *)a;
    gd(V_a, x) = -gd(V_a, x);
    gd(V_a, y) = -gd(V_a, y);
    gd(V_a, z) = -gd(V_a, z);
    return V_a;
}
/// векторное произведение
void *cross_Complex(void *a, void *b)
{
    Begin_Complex;
    gc(vec, x) = gc(V_a, y) * gc(V_b, z) - gc(V_a, z) * gc(V_b, y);
    gc(vec, y) = -gc(V_a, x) * gc(V_b, z) + gc(V_a, z) * gc(V_b, x);
    gc(vec, z) = gc(V_a, x) * gc(V_b, y) - gc(V_a, y) * gc(V_a, x);
    return vec;
}
/// векторное произведение
void *cross_double(void *a, void *b)
{
    Begin_double;
    gd(vec, x) = gd(V_a, y) * gd(V_b, z) - gd(V_a, z) * gd(V_b, y);
    gd(vec, y) = -gd(V_a, x) * gd(V_b, z) + gd(V_a, z) * gd(V_b, x);
    gd(vec, z) = gd(V_a, x) * gd(V_b, y) - gd(V_a, y) * gd(V_a, x);
    return vec;
}
/// вывод вектора
void print_Complex(Vertex *a)
{
    printf("{%.3f %+.3fi, %.3f %+.3fi, %.3f %+.3fi}\n", creal(gc(a, x)), cimag(gc(a, x)), creal(gc(a, y)), cimag(gc(a, y)), creal(gc(a, z)), cimag(gc(a, z)));
}
void print_double(Vertex *a)
{
    printf("{%.3f, %.3f, %.3f}\n", *(double *)(*a).x, *(double *)(*a).y, *(double *)(*a).z);
}
/// ввод вектора
void *scan_Complex()
{
    Vertex *t = create_Complex();
    (*t).x = malloc(sizeof(double _Complex));
    (*t).y = malloc(sizeof(double _Complex));
    (*t).z = malloc(sizeof(double _Complex));
    double a, b;
    //double _Complex *res;
    scanf("%lf%lf", &a, &b);
    //*(_C_double_complex *)((*t).x) = _Cbuild(a, b);
    gc(t, x) = a + b * I;
    scanf("%lf%lf", &a, &b);
    gc(t, y) = a + b * I;
    //*(_C_double_complex *)((*t).y) = _Cbuild(a, b);
    scanf("%lf%lf", &a, &b);
    gc(t, z) = a + b * I;
    //*(_C_double_complex *)((*t).z) = _Cbuild(a, b);
    return t;
}
/// ввод вектора
void *scan_double()
{
    Vertex *t = create_double();
    (*t).x = malloc(sizeof(double));
    (*t).y = malloc(sizeof(double));
    (*t).z = malloc(sizeof(double));
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    gd(t, x) = a;
    gd(t, y) = b;
    gd(t, z) = c;
    return t;
}