#include <stdio.h>
#include <math.h>

typedef struct {
    double alpha; // alpha açısı (derece)
    double a;     // a uzunluğu
    double d;     // d uzunluğu
    double theta; // theta açısı (derece)
} DHParameters;

typedef struct {
    double x;
    double y;
    double z;
} Position;

typedef struct {
    double roll;  // x ekseninde dönüş (derece)
    double pitch; // y ekseninde dönüş (derece)
    double yaw;   // z ekseninde dönüş (derece)
} Orientation;

void forwardKinematics(const DHParameters dh_params[], int num_joints, Position *pos, Orientation *orient) {
    // Başlangıç konumu ve yönelim
    pos->x = 0.0;
    pos->y = 0.0;
    pos->z = 0.0;

    orient->roll = 0.0;
    orient->pitch = 0.0;
    orient->yaw = 0.0;

    // DH parametrelerini kullanarak forward kinematik hesapla
    for (int i = 0; i < num_joints; i++) {
        double theta_rad = dh_params[i].theta * M_PI / 180.0;
        double alpha_rad = dh_params[i].alpha * M_PI / 180.0;

        double cos_theta = cos(theta_rad);
        double sin_theta = sin(theta_rad);
        double cos_alpha = cos(alpha_rad);
        double sin_alpha = sin(alpha_rad);

        // Hesaplama adımları
        double A = dh_params[i].a * cos_theta;
        double B = dh_params[i].a * sin_theta;
        double C = dh_params[i].d * cos_alpha;
        double D = dh_params[i].d * sin_alpha;

        // Yeni konumu ve yönelimi güncelle
        pos->x += A;
        pos->y += B;
        pos->z += C;

        orient->roll += dh_params[i].theta;
        orient->yaw += dh_params[i].alpha;
    }
}

int main() {
    // 6 eksenli robot için DH parametreleri (örnek değerler)
    DHParameters dh_params[] = {
        {90.0, 0.0, 0.5, 45.0},
        {-90.0, 0.0, 0.0, 30.0},
        {0.0, 1.0, 0.0, 60.0},
        {90.0, 0.0, 0.0, 90.0},
        {-90.0, 0.0, 0.2, 0.0},
        {0.0, 0.5, 0.0, 30.0},
    };

    // Hesaplanacak konum ve yönelim
    Position pos;
    Orientation orient;

    // İleri kinematik hesaplamasını yap
    forwardKinematics(dh_params, sizeof(dh_params) / sizeof(dh_params[0]), &pos, &orient);

    // Sonuçları ekrana yazdır
    printf("Konum: (%.2f, %.2f, %.2f)\n", pos.x, pos.y, pos.z);
    printf("Yönelim: (Roll=%.2f, Pitch=%.2f, Yaw=%.2f)\n", orient.roll, orient.pitch, orient.yaw);

    return 0;
}
