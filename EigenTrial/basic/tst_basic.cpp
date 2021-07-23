#include <QtTest>
#include <iostream>
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
    void special_matrices();
    void matrix_operations();

    void n_vector();

    void elements_is_not_initialized_by_default();

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

void Basic::special_matrices()
{
    using Eigen::Matrix3d;
    using Eigen::MatrixXd;

    // 単位行列
    auto&& identity = Matrix3d::Identity();
    qDebug() << "identity: " << endl << serialize( identity ).c_str();

    // ゼロ行列
    auto&& zero = Matrix3d::Zero();
    qDebug() << "zero: " << endl << serialize( zero ).c_str();

    // 要素が全て"1"の行列
    auto&& ones = Matrix3d::Ones();
    qDebug() << "ones: " << endl << serialize( ones ).c_str();

    // Constant()により、全ての要素を指定した値で埋める
    auto&& constant = Matrix3d::Constant( 1.23 );
    qDebug() << "constant: " << endl << serialize( constant ).c_str();

    // サイズ指定も可能
    auto&& constant2 = MatrixXd::Constant( 2, 3, 2.34 );
    QCOMPARE( constant2.rows(), 2 );
    QCOMPARE( constant2.cols(), 3 );
    qDebug() << "constant2: " << endl << serialize( constant2 ).c_str();

    // Note: setXXX()という同名のメンバ関数もある
}

void Basic::matrix_operations()
{
    using Eigen::MatrixXd;
    using Eigen::Matrix2d;

    Matrix2d m;
    m << 11.0, 12.0,
         21.0, 22.0;

    MatrixXd m4 = MatrixXd::Random( 4, 4 );

    // 転置行列
    {
        Matrix2d expected;
        expected << 11.0, 21.0, 12.0, 22.0;
        QCOMPARE( m.transpose(), expected );
    }
    // 逆行列
    {
        Matrix2d inv = m.inverse();
        qDebug() << endl << serialize( inv ).c_str();
    }
    // 対角行列
    {
        // diagonal()で、対角ベクトルを取得できる
        auto&& v = m.diagonal();
        QCOMPARE( v(0), 11.0 );
        QCOMPARE( v(1), 22.0 );

        // asDiagonal()で、ベクトルから対角行列を取得できる
        auto&& diag = v.asDiagonal();

        Matrix2d expected;
        expected << 11.0, 0.0,
                    0.0, 22.0;
        QCOMPARE( diag.toDenseMatrix(), expected );
    }
    // 部分行列
    {
        // 行ベクトル
        auto&& row0 = m.row( 0 );
        QCOMPARE( row0(0), 11.0 );
        QCOMPARE( row0(1), 12.0 );

        // 列ベクトル
        auto&& col0 = m.col(0);
        QCOMPARE( col0(0), 11.0 );
        QCOMPARE( col0(1), 21.0 );

        qDebug() << endl
                 << serialize( m4 ).c_str();

        // block()により、任意の部分行列を取得できる
        auto&& block = m4.block( 0, 1, 2, 2 );  // (1,2)要素を起点に、2x2の部分行列を取得する
        qDebug() << endl << serialize( block ).c_str();

        // block()以外にも、以下の部分行列取得メソッドが準備されている
        // - topLeftCorner()
        // - topRightCorner()
        // - bottomLeftCorner()
        // - bottomRightCorner()
        qDebug() << endl
                 << serialize( m4.topLeftCorner( 2, 2 ) ).c_str() << endl << "---" << endl
                 << serialize( m4.topRightCorner( 2, 2 ) ).c_str() << endl << "---" << endl
                 << serialize( m4.bottomLeftCorner( 2, 2 ) ).c_str() << endl << "---" << endl
                 << serialize( m4.bottomRightCorner( 2, 2 ) ).c_str() << endl;
    }
}

void Basic::n_vector()
{
    // サイズ3の行ベクトル
    Eigen::VectorXd v( 3 );
    v(0) = 1.1;
    v(1) = 2.2;
    v(2) = 3.3;
    QCOMPARE( v.rows(), 3 );
    QCOMPARE( v.cols(), 1 );
    qDebug() << endl << serialize( v ).c_str();

    // サイズ3の列ベクトル
    Eigen::RowVectorXd v2( 3 );
    v2(0) = 4.4;
    v2(1) = 5.5;
    v2(2) = 6.6;
    QCOMPARE( v2.rows(), 1 );
    QCOMPARE( v2.cols(), 3 );
    qDebug() << endl << serialize( v2 ).c_str();

    Eigen::Vector2d v3( 3.0, 4.0 );
    QCOMPARE( v3(0), 3.0 );
    QCOMPARE( v3(1), 4.0 );

    // ノルム
    {
        QCOMPARE( v3.norm(), 5.0 );  // 大きさ(L2ノルム)
        QCOMPARE( v3.squaredNorm(), 25.0 );  // 2乗ノルム

        QCOMPARE( v3.lpNorm<1>(), 7.0 );  // L1ノルム
        QCOMPARE( v3.lpNorm<2>(), 5.0 );  // L2ノルム
    }
    // 正規化
    {
        // normalized()は、正規化したベクトル(大きさ1のベクトル)を返す
        QCOMPARE( v3.normalized(), Eigen::Vector2d( 0.6, 0.8 ) );

        // normalize()は、正規化する
        v3.normalize();
        QCOMPARE( v3, Eigen::Vector2d( 0.6, 0.8 ) );
    }
}

/**
 * @brief デフォルトでは、要素は不定値となる
 *
 * EIGEN_INITIALIZE_MATRICES_BY_ZERO を定義することにより、0で初期化されるようになる
 * see. InitializeMacroTest
 */
void Basic::elements_is_not_initialized_by_default()
{
    auto&& m = new Eigen::Matrix2i();
    QVERIFY( (*m)(0,0) != 0 );
    QVERIFY( (*m)(0,1) != 0 );
    QVERIFY( (*m)(1,0) != 0 );
    QVERIFY( (*m)(1,1) != 0 );
    delete m;
}

QTEST_APPLESS_MAIN(Basic)

#include "tst_basic.moc"
