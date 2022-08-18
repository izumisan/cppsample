#include <QtTest>
#include <Eigen/Dense>

static const double deg2rad_ = M_PI / 180.0;

class CoordinateConversion : public QObject
{
    Q_OBJECT

public:
    CoordinateConversion();
    ~CoordinateConversion();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void coordinate_conversion_matrix();
};

CoordinateConversion::CoordinateConversion()
{
}

CoordinateConversion::~CoordinateConversion()
{
}

void CoordinateConversion::initTestCase()
{
}

void CoordinateConversion::cleanupTestCase()
{
}

void CoordinateConversion::coordinate_conversion_matrix()
{
    using Eigen::Matrix3d;
    using Eigen::Vector3d;

    /*
    U座標系からV座標系への座標変換マトリクス

            |  cosθ  sinθ  0 |
    Tz(θ) = | -sinθ  cosθ  0 |
            |     0     0  1 |

    ここで、 θはU座標系->V座標系へのZ軸周りの角度
    */

    auto&& theta = 10.0 * deg2rad_;
    auto&& Tz = Matrix3d();
    Tz << qCos( theta ), qSin( theta ), 0.0,
          -qSin( theta ), qCos( theta ), 0.0,
          0.0, 0.0, 1.0;

    // 1. U座標系におけるベクトル(1,0,0)をV座標系に座標変換
    {
        auto&& u = Vector3d();
        u << 1.0, 0.0, 0.0;

        auto&& v = Tz * u;
        qDebug() << "[1]" << u(0) << u(1) << u(2) << "->" << v(0) << v(1) << v(2);  // 1 0 0 -> 0.984808 -0.173648 0
    }
    // 2. U座標系におけるベクトル(0,1,0)をV座標系に座標変換
    {
        auto&& u = Vector3d();
        u << 0.0, 1.0, 0.0;

        auto&& v = Tz * u;
        qDebug() << "[2]" << u(0) << u(1) << u(2) << "->" << v(0) << v(1) << v(2);  // 0 1 0 -> 0.173648 0.984808 0
    }
    // 3. U座標系におけるベクトル(0,0,1)をV座標系に座標変換
    {
        auto&& u = Vector3d();
        u << 0.0, 0.0, 1.0;

        auto&& v = Tz * u;
        qDebug() << "[3]" << u(0) << u(1) << u(2) << "->" << v(0) << v(1) << v(2);  // 0 0 1 -> 0 0 1
    }
    // 4. U座標系におけるベクトル(1/√2,1/√2,1)をV座標系に座標変換
    {
        auto&& u = Vector3d();
        u << 1.0 / qSqrt( 2.0 ), 1.0 / qSqrt( 2.0 ), 1.0;

        auto&& v = Tz * u;
        qDebug() << "[4]" << u(0) << u(1) << u(2) << "->" << v(0) << v(1) << v(2);  // 0.707107 0.707107 1 -> 0.819152 0.573576 1
    }
}

QTEST_APPLESS_MAIN(CoordinateConversion)

#include "tst_coordinateconversion.moc"
