//C++ OOP Revision — Inheritance & Operator Overloading
#include <iostream> // مكتبة الإدخال والإخراج
using namespace std; // حتى نستخدم cout بدون std::

class shape { // الكلاس الأب الذي سترث منه الأشكال
protected: // متاح داخل الكلاس والكلاسات المشتقة
    double area; // متغير لتخزين المساحة
    double para; // متغير لتخزين المحيط

public: // أعضاء يمكن الوصول إليها من خارج الكلاس
    void printarea() { // دالة لطباعة المساحة
        cout << "Area = " << area << endl; // طباعة قيمة المساحة
    }

    void printpara() { // دالة لطباعة المحيط
        cout << "para = " << para << endl; // طباعة قيمة المحيط
    }
};

class square : public shape { // كلاس المربع يرث من shape
    double side; // ضلع المربع، وهو private افتراضيًا

public: // بداية الأعضاء العامة

    square() { // Default Constructor: المنشئ الافتراضي
        side = 5; // إعطاء الضلع قيمة ابتدائية 5
    }

    square(int s) { // Parameterized Constructor: منشئ بمعامل
        side = s; // تخزين القيمة المرسلة في الضلع
    }

    void computearea() { // دالة حساب مساحة المربع
        area = side * side; // المساحة = الضلع × الضلع
    }

    void computepara(); // إعلان دالة حساب المحيط

    friend void fun(); // السماح للدالة fun بالوصول لأعضاء square الخاصة

    square operator+(square s) { // إعادة تعريف + لجمع كائنين من square
        square temp; // إنشاء كائن مؤقت، ضلعه الابتدائي 5
        temp.side = side + s.side; // جمع ضلعي الكائنين
        temp.computepara(); // حساب محيط الكائن المؤقت
        temp.computearea(); // حساب مساحة الكائن المؤقت
        return temp; // إعادة الكائن الناتج
    }
};

class Rec : public shape { // كلاس المستطيل يرث من shape
    double length, width; // متغيرا الطول والعرض

public: // بداية الأعضاء العامة

    Rec() { // المنشئ الافتراضي للمستطيل
        length = 5; // تعيين الطول 5
        width = 10; // تعيين العرض 10
    }

    Rec(int l, int w) { // منشئ يستقبل الطول والعرض
        length = l; // تخزين الطول المرسل
        width = w; // تخزين العرض المرسل
    }

    void computearea() { // دالة حساب مساحة المستطيل
        area = length * width; // المساحة = الطول × العرض
    }

    void computepara(); // إعلان دالة حساب محيط المستطيل
};

void fun() { // تعريف الدالة الصديقة خارج الكلاس
    square s; // إنشاء مربع ضلعه 5
    s.side = 10; // تعديل الضلع رغم أنه private بسبب friend
    s.area = s.side * s.side; // حساب المساحة وتخزينها
}

int main() { // نقطة بداية تنفيذ البرنامج
    square s1, s2(8), s3(6); // إنشاء مربعات أضلاعها 5 و8 و6

    s3 = s1 + s2; // جمع ضلعي s1 وs2 وإسناد الناتج إلى s3

    s3.computearea(); // إعادة حساب مساحة s3
    s3.computepara(); // إعادة حساب محيط s3

    s3.printpara(); // طباعة المحيط
    s3.printarea(); // طباعة المساحة

    return 0; // إنهاء البرنامج بنجاح
}

void square::computepara() { // تعريف دالة المحيط خارج الكلاس
    para = side * 4; // محيط المربع = الضلع × 4
}


/* الناتج المتوقع
para = 52
Area = 169

 ملاحظات مهمة

- `protected`: يسمح للكلاسات المشتقة باستخدام المتغيرات.
- `private`: يمنع الوصول المباشر من خارج الكلاس.
- `friend`: يسمح للدالة الصديقة بالوصول إلى الأعضاء الخاصة.
- `operator+`: يحدد كيف تعمل علامة الجمع مع الكائنات.
- `::`: يسمى Scope Resolution Operator، ويحدد الكلاس الذي تتبع له الدالة.
- المنشئ لا يحسب المساحة والمحيط تلقائيًا؛ يجب استدعاء دوال الحساب.
- `Rec::computepara()` معلنة فقط هنا ولم نعرّفها؛ أضف تعريفها إذا أردت استخدامها.*/
