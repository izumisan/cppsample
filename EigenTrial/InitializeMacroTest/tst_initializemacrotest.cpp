#include <QtTest>
#include <Eigen/Dense>

class InitializeMacroTest : public QObject
{
    Q_OBJECT

public:
    InitializeMacroTest();
    ~InitializeMacroTest();

private slots:
    void elements_is_initialized_if_defined_EIGEN_INITIALIZE_MATRICES_BY_ZERO();

};

InitializeMacroTest::InitializeMacroTest()
{
}

InitializeMacroTest::~InitializeMacroTest()
{
}

/**
 * @brief EIGEN_INITIALIZE_MATRICES_BY_ZERO を定義すると、要素が0で初期化されるようになる
 */
void InitializeMacroTest::elements_is_initialized_if_defined_EIGEN_INITIALIZE_MATRICES_BY_ZERO()
{
    auto&& m = new Eigen::Matrix2i();
    QCOMPARE( (*m)(0,0), 0 );
    QCOMPARE( (*m)(0,1), 0 );
    QCOMPARE( (*m)(1,0), 0 );
    QCOMPARE( (*m)(1,1), 0 );

    delete m;
}

QTEST_APPLESS_MAIN(InitializeMacroTest)

#include "tst_initializemacrotest.moc"
