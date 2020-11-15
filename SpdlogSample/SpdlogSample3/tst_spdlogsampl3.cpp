#include <QtTest>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/async_logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

class SpdlogSampl3 : public QObject
{
    Q_OBJECT

public:
    SpdlogSampl3();
    ~SpdlogSampl3();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void logging_to_console_and_file_test();
};

SpdlogSampl3::SpdlogSampl3()
{
}

SpdlogSampl3::~SpdlogSampl3()
{
}

void SpdlogSampl3::initTestCase()
{
}

void SpdlogSampl3::cleanupTestCase()
{
    spdlog::shutdown();
}

void SpdlogSampl3::logging_to_console_and_file_test()
{
    {
        // コンソールとログファイルに出力するloggerのセットアップ
        // - sinkオブジェクトを生成し、sinkリストを指定したloggerを作成(セットアップ)する
        spdlog::init_thread_pool( 8192, 1 );  // queue size: 8k, thread size: 1 (default)

        auto&& console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        auto&& file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>( "logs/foo.log", 0, 0 );  // logs/foo_yyyy-MM-dd.log. logsディレクトリは自動で作成される.

        std::vector<spdlog::sink_ptr> sinks { console_sink, file_sink };
        auto&& logger = std::make_shared<spdlog::async_logger>( "foo", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block );

        spdlog::register_logger( logger );  // register_logger()により、spdlog::get(name)でloggerを取得できるようになる.
    }
    {
        auto&& logger = spdlog::get( "foo" );
        logger->critical( "critical message" );
        logger->error( "error message" );
        logger->warn( "warn message" );
        logger->info( "info message" );
        logger->debug( "debug message" );
        logger->trace( "trace message" );
    }
}

QTEST_APPLESS_MAIN(SpdlogSampl3)

#include "tst_spdlogsampl3.moc"
