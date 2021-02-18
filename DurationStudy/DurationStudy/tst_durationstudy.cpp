#include <QtTest>
#include <chrono>

class DurationStudy : public QObject
{
    Q_OBJECT

public:
    DurationStudy();
    ~DurationStudy();

private slots:
    void duration_1();
    void duration_2();
    void duration_3();
};

DurationStudy::DurationStudy()
{
}

DurationStudy::~DurationStudy()
{
}

void DurationStudy::duration_1()
{
    std::chrono::seconds sec( 1 );  // 1sec

    {
        // std::chrono::millisecondsのコンストラクタにstd::chrono::secondsを指定することで、sec->msecに単位変換
        std::chrono::milliseconds msec( sec );
        QCOMPARE( msec.count(), 1000 );  // 1000 msec
    }
    {
        // duratioin_castにより、sec->msecに単位変換
        std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::seconds>( sec );
        QCOMPARE( msec.count(), 1000 );
    }
}

void DurationStudy::duration_2()
{
    std::chrono::milliseconds msec( 1234 );  // 1234 msec = 1.234 sec

    // std::chrono::secondsのコンストラクタにstd::chrono::millisecondsは指定できない
    // std::chrono::seconds sec( msec );

    // duration_castにより、msec->secに単位変換
    // ただし、std::chrono::seconds は std::chrono::duration<long, long>のエイリアスの整数型なので、
    // msec->secのduration_castで桁落ち（切り捨て）により、1.234secとはならない
    std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>( msec );
    QCOMPARE( sec.count(), 1 );
}

void DurationStudy::duration_3()
{
    // msec->secを浮動小数点で単位変換するには、double対応のseconds, millisecondsを作ってしまえばよい

    using seconds = std::chrono::duration<double, std::ratio<1>>;
    using milliseconds = std::chrono::duration<double, std::milli>;  // std::chrno::duration<double, std::ratio<1,1000>>でもよい.　std::milli は std::ration<1,1000>のエイリアス

    milliseconds msec( 1234 );  // 1234 msec

    {
        // コンストラクタにより msec->sec に単位変換
        seconds sec( msec );
        QCOMPARE( sec.count(), 1.234 );
    }
    {
        // duration_castにより、msec->sec に単位変換
        seconds sec = std::chrono::duration_cast<seconds>( msec );
        QCOMPARE( sec.count(), 1.234 );
    }
}

QTEST_APPLESS_MAIN(DurationStudy)

#include "tst_durationstudy.moc"
