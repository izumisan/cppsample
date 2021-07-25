#include <QtTest>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>

static const double deg2rad_ = M_PI / 180.0;

class Transform : public QObject
{
    Q_OBJECT

public:
    Transform();
    ~Transform();

private slots:
    void translation();
    void scaling();
    void rotation();
    void rotation2();
    void quaternion();

private:
    template<class T>
    std::string serialize( const T& m )
    {
        std::stringstream ss;
        ss << m;
        return ss.str();
    }
};

Transform::Transform()
{
}

Transform::~Transform()
{
}

void Transform::translation()
{
    Eigen::Vector3d v( 1.0, 2.0, 3.0 );

    // 平行移動
    Eigen::Translation<double, 3> tans( 11.0, 12.0, 13.0 );  // `Translation<double, 3>`は`Translation3d`でも可

    auto&& v2 = tans * v;
    QCOMPARE( v2, Eigen::Vector3d( 12.0, 14.0, 16.0 ) );
}

void Transform::scaling()
{
    Eigen::Vector3d v( 1.0, 1.0, 1.0 );

    // Scalingメソッドにより、拡大・縮小用の対角行列を生成する
    Eigen::DiagonalMatrix<double, 3> scale = Eigen::Scaling( 1.0, 2.0, 3.0 );

    auto&& v2 = scale * v;
    QCOMPARE( v2, Eigen::Vector3d( 1.0, 2.0, 3.0 ) );
}

void Transform::rotation()
{
    Eigen::Vector3d v = Eigen::Vector3d( 1.0, 0.0, 0.0 );

    // X軸回りに30deg回転するアフィン変換
    Eigen::AngleAxisd rx = Eigen::AngleAxisd( 10.0 * deg2rad_, Eigen::Vector3d::UnitX() );
    // Y軸回りに30deg回転するアフィン変換
    Eigen::AngleAxisd ry = Eigen::AngleAxisd( 20.0 * deg2rad_, Eigen::Vector3d::UnitY() );
    // Z軸回りに30deg回転するアフィン変換
    Eigen::AngleAxisd rz = Eigen::AngleAxisd( 30.0 * deg2rad_, Eigen::Vector3d::UnitZ() );

    qDebug() << endl
             << "rotation 10 around x" << endl
             << serialize( rx * v ).c_str() << endl
             << "rotation 20 around y" << endl
             << serialize( ry * v ).c_str() << endl
             << "rotation 30 around z" << endl
             << serialize( rz * v ).c_str();

    // X -> Y -> Z の順序で回転する回転行列
    Eigen::Matrix3d rot( rz * ry * rx );
    qDebug() << endl << serialize( rot * v ).c_str();

    // X -> Y -> Z の順序で回転させた座標変換行列
    Eigen::Matrix3d rot2( rx * ry * rz );
    // 座標変換行列からオイラー角を求める
    // (eulerAngles()の引数は、回転順序を示す)
    qDebug() << endl << serialize( rot2.eulerAngles( 0, 1, 2 ) ).c_str();
}

void Transform::rotation2()
{
    Eigen::Vector3d v( 10.0, 0.0, 0.0 );

    // 回転行列による回転
    {
        Eigen::Vector3d axis( 0.0, 0.0, 1.0 );  // 回転軸(Z軸)
        Eigen::AngleAxisd rot( 90.0 * deg2rad_, axis );  // 回転軸(Z軸)周りに90deg回転する回転行列

        auto&& rotated = rot * v;
        qDebug() << rotated(0) << rotated(1) << rotated(2);
    }
    // クォータニオンによる回転
    {
        Eigen::Vector3d axis( 0.0, 0.0, 1.0 );  // 回転軸(Z軸)
        Eigen::AngleAxisd rot( 90.0 * deg2rad_, axis );  // 回転軸(Z軸)周りに90deg回転する回転行列
        Eigen::Quaterniond quat( rot );  // Z軸回りに90deg回転する回転行列からクォータニオンを生成

        auto&& rotated = quat * v;  // クォータニオンによる回転
        qDebug() << rotated(0) << rotated(1) << rotated(2);
    }
}

void Transform::quaternion()
{
    // 方向ベクトル(λx,λy,λz)を回転軸として角度θ回転させるクォータニオン(四元数ベクトル)
    // -> (w: cos(θ/2), x: λxsin(θ/2), y: λysin(θ/2), z: λzsin(θ/2))

    // Z軸(0,0,1)周りに45deg回転するクォータニオン
    auto&& theta = 45.0 * deg2rad_;
    auto&& theta_2 = theta * 0.5;
    Eigen::Quaterniond q( qCos( theta_2 ), 0.0, 0.0, qSin( theta_2 ) );  // コンストラクタで(w,x,y,z)を指定

    Eigen::Vector3d v = Eigen::Vector3d::UnitX();

    // ベクトルvをクォータニオンqで回転(qvq_conjugate)
    auto&& v2 = q * v;  // "*"演算子で、 q * v * q.conjugate() を実施してくれるので、共役成分を含める必要はない
    qDebug() << v2(0) << v2(1) << v2(2);  //=> 0.707107 0.707107 0

    // 共役クォータニオン
    // (共役なクォータニオンは逆回転を表す -> Z軸周りに-45deg回転)
    auto&& q2 = q.conjugate();

    auto&& v3 = q2 * v;
    qDebug() << v3(0) << v3(1) << v3(2);  //=> 0.707107 -0.707107 0
}

QTEST_APPLESS_MAIN(Transform)

#include "tst_transform.moc"
