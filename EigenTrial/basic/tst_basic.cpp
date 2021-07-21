#include <QtTest>
#include <sstream>
// ".h"ではないことに注意
#include <Eigen/Dense>

class Basic : public QObject
{
    Q_OBJECT

public:
    Basic();
    ~Basic();

private slots:
    void matrix2d_test();
    void mxn_matrix();
    void matrix_types();

private:
    template<class T>
    std::string serialize( const T& m )
    {
        std::stringstream ss;
        ss << m;
        return ss.str();
    }
};

Basic::Basic()
{
}

Basic::~Basic()
{
}
////////////////////////////////////////////////////////////////////////////////

void Basic::matrix2d_test()
{
    Eigen::Matrix2d m;
    m(0, 0) = 11.0;
    m(0, 1) = 12.0;
    m(1, 0) = 21.0;
    m(1, 1) = 22.0;

    qDebug() << endl << serialize( m ).c_str();
}

void Basic::mxn_matrix()
{
    {
        // 2x3 matrix
        Eigen::MatrixXd m( 2, 3 );
        m(0,0) = 11.0;
        m(0,1) = 12.0;
        m(0,2) = 13.0;
        m(1,0) = 21.0;
        m(1,1) = 22.0;
        m(1,2) = 23.0;

        qDebug() << endl << serialize( m ).c_str();
    }
    {
        // "MatrixXd"は、"Matrix<double, row, col>"のtypedef

        // 2x3 matrix
        Eigen::Matrix<double, 2, 3> m;
        m(0,0) = 11.0;
        m(0,1) = 12.0;
        m(0,2) = 13.0;
        m(1,0) = 21.0;
        m(1,1) = 22.0;
        m(1,2) = 23.0;

//        qDebug() << endl << serialize( m ).c_str();
    }
    {
        Eigen::MatrixXd m( 2, 3 );

        // 挿入演算子(<<)で代入可能
        m << 11.0, 12.0, 13.0,
             21.0, 22.0, 23.0;

        qDebug() << endl << serialize( m ).c_str();
    }
}

void Basic::matrix_types()
{
    using Eigen::Matrix3d;

    // 単位行列
    auto&& identity = Matrix3d::Identity();
    qDebug() << "identity: " << endl << serialize( identity ).c_str();

    // ゼロ行列
    auto&& zero = Matrix3d::Zero();
    qDebug() << "zero: " << endl << serialize( zero ).c_str();

    // 要素が全て"1"の行列
    auto&& ones = Matrix3d::Ones();
    qDebug() << "ones: " << endl << serialize( ones ).c_str();

    // 要素が全て指定した値の行列
    auto&& sameElement = Matrix3d::Constant( 1.23 );
    qDebug() << "sameElement: " << endl << serialize( sameElement ).c_str();

    // Note: setXXX()という同名のメンバ関数もある
}

QTEST_APPLESS_MAIN(Basic)

#include "tst_basic.moc"
