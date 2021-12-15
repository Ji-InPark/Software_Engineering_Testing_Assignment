#include "pch.h"

#include "../DWS_Error/DisplayControl.c"
#include "../DWS_Error/LightControl.c"
#include "../DWS_Error/ETC.c"
#include "../DWS_Error/AlarmControl.c"

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

// 202011299 박지인
TEST(CheckAlarmSuite, CheckAlarmTest1) {
	static ALARM r;
	static MODE md;
	static TIME t;

	r.CHECK_ALARM = 0;

	md.M_TS = 0;
	md.M_ALS = 0;
	md.ALARM_INDI_ON = 1;
	t.second = 0;
	t.centisecond = 0;

	r.month = 0;
	r.day = 0;

	t.hour = 12;
	t.minute = 30;
	r.hour = 12;
	r.minute = 30;

	CheckAlarm(&r, &md, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
}

// 202011299 박지인
TEST(CheckAlarmSuite, CheckAlarmTest2) {
	static ALARM r;
	static MODE md;
	static TIME t;

	r.CHECK_ALARM = 0;

	md.M_TS = 0;
	md.M_ALS = 0;
	md.ALARM_INDI_ON = 1;
	t.second = 0;
	t.centisecond = 0;

	r.month = 0;
	r.day = 1;

	t.day = 1;

	t.hour = 12;
	t.minute = 30;
	r.hour = 12;
	r.minute = 30;

	CheckAlarm(&r, &md, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
}

// 202011299 박지인
TEST(CheckAlarmSuite, CheckAlarmTest3) {
	static ALARM r;
	static MODE md;
	static TIME t;

	r.CHECK_ALARM = 0;

	md.M_TS = 0;
	md.M_ALS = 0;
	md.ALARM_INDI_ON = 1;
	t.second = 0;
	t.centisecond = 0;

	r.month = 1;
	r.day = 0;

	t.month = 1;

	t.hour = 12;
	t.minute = 30;
	r.hour = 12;
	r.minute = 30;

	CheckAlarm(&r, &md, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
}

// 202011299 박지인
TEST(CheckAlarmSuite, CheckAlarmTest4) {
	static ALARM r;
	static MODE md;
	static TIME t;

	r.CHECK_ALARM = 0;

	md.M_TS = 0;
	md.M_ALS = 0;
	md.ALARM_INDI_ON = 1;
	t.second = 0;
	t.centisecond = 0;

	r.month = 1;
	r.day = 1;

	t.month = 1;
	t.day = 1;

	t.hour = 12;
	t.minute = 30;
	r.hour = 12;
	r.minute = 30;

	CheckAlarm(&r, &md, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
}

// 202011299 박지인
TEST(CheckAlarmSuite, CheckAlarmTest5) {
	static ALARM r;
	static MODE md;
	static TIME t;

	r.CHECK_ALARM = 0;

	md.M_TS = 0;
	md.M_ALS = 0;
	md.ALARM_INDI_ON = 1;
	t.second = 0;
	t.centisecond = 0;

	r.month = 0;
	r.day = 0;

	t.month = 1;
	t.day = 1;

	t.hour = 12;
	t.minute = 30;
	r.hour = 12;
	r.minute = 30;

	CheckAlarm(&r, &md, &t);

	EXPECT_EQ(r.CHECK_ALARM, 1);
}

// 202011299 박지인
TEST(AlarmIndicatorSuite, AlarmIndicatorTest1) {
	static MODE md;

	md.ALARM_INDI_ON = 1;

	AlarmIndicator(&md);

	EXPECT_EQ(md.ALARM_INDI_ON, 0);
}

// 202011299 박지인
TEST(AlarmIndicatorSuite, AlarmIndicatorTest2) {
	static MODE md;

	md.ALARM_INDI_ON = 0;

	AlarmIndicator(&md);

	EXPECT_EQ(md.ALARM_INDI_ON, 1);
}

// 202011299 박지인
TEST(IncreaseAlarmValueSuite, IncreaseAlarmValueTest1) {
	static ALARM r;
	static MODE md;

	md.AL_month = 1;

	r.month = 1;
	r.day = 30;
	r.hour = 3;
	r.minute = 54;

	IncreaseAlarmValue(&r, &md);

	EXPECT_EQ(r.month, 2);
	EXPECT_EQ(r.day, 0);
	EXPECT_EQ(r.hour, 3);
	EXPECT_EQ(r.minute, 54);
}

// 202011299 박지인
TEST(IncreaseAlarmValueSuite, IncreaseAlarmValueTest2) {
	static ALARM r;
	static MODE md;

	md.AL_month = 1;

	r.month = 3;
	r.day = 31;
	r.hour = 3;
	r.minute = 54;

	IncreaseAlarmValue(&r, &md);

	EXPECT_EQ(r.month, 4);
	EXPECT_EQ(r.day, 0);
	EXPECT_EQ(r.hour, 3);
	EXPECT_EQ(r.minute, 54);
}

// 202011299 박지인
TEST(IncreaseAlarmValueSuite, IncreaseAlarmValueTest3) {
	static ALARM r;
	static MODE md;

	md.AL_day = 1;

	r.month = 3;
	r.day = 31;
	r.hour = 3;
	r.minute = 54;

	IncreaseAlarmValue(&r, &md);

	EXPECT_EQ(r.month, 3);
	EXPECT_EQ(r.day, 0);
	EXPECT_EQ(r.hour, 3);
	EXPECT_EQ(r.minute, 54);
}

// 202011299 박지인
TEST(IncreaseAlarmValueSuite, IncreaseAlarmValueTest4) {
	static ALARM r;
	static MODE md;

	md.AL_day = 1;

	r.month = 4;
	r.day = 30;
	r.hour = 3;
	r.minute = 54;

	IncreaseAlarmValue(&r, &md);

	EXPECT_EQ(r.month, 4);
	EXPECT_EQ(r.day, 0);
	EXPECT_EQ(r.hour, 3);
	EXPECT_EQ(r.minute, 54);
}

// 202011299 박지인
TEST(LapTimeResetSuite, LapTimeResetTest1) {
	static STOPWATCH sw;
	static MODE md;

	for (int csec = 0; csec < 100; csec += 10)
	{
		sw.Lap_Cse = csec;
		for (int sec = 0; sec < 60; sec += 6)
		{
			sw.Lap_se = sec;
			for (int min = 0; min < 100; min += 10)
			{
				sw.Lap_min = min;

				LapTimeReset(&sw, &md);

				EXPECT_EQ(sw.Lap_Cse, 0);
				EXPECT_EQ(sw.Lap_se, 0);
				EXPECT_EQ(sw.Lap_min, 0);
				EXPECT_EQ(md.LAP_ON, 0);
			}
		}
	}
}

// 202011299 박지인
TEST(IncreaseValueSuite, IncreaseValueTest1) {
	static MODE md;
	static TIME t;

	t.year = 2012;
	t.month = 2;
	t.day = 28;

	md.TS_day = 1;

	IncreaseValue(&md, &t);

	EXPECT_EQ(t.day, 29);
}

// 202011299 박지인
TEST(IncreaseValueSuite, IncreaseValueTest2) {
	static MODE md;
	static TIME t;

	t.year = 2012;
	t.month = 4;
	t.day = 30;

	md.TS_day = 1;

	IncreaseValue(&md, &t);

	EXPECT_EQ(t.day, 1);
}

// 202011299 박지인
TEST(IncreaseValueSuite, IncreaseValueTest3) {
	static MODE md;
	static TIME t;

	t.year = 2012;
	t.month = 1;
	t.day = 30;

	md.TS_day = 1;

	IncreaseValue(&md, &t);

	EXPECT_EQ(t.day, 31);
}

// 202011299 박지인
TEST(IncreaseValueSuite, IncreaseValueTest4) {
	static MODE md;
	static TIME t;

	t.year = 2013;
	t.month = 2;
	t.day = 28;

	md.TS_day = 1;

	IncreaseValue(&md, &t);

	EXPECT_EQ(t.day, 1);
}

// 202011299 박지인
TEST(IncreaseValueSuite, IncreaseValueTest5) {
	static MODE md;
	static TIME t;

	t.year = 2013;
	t.month = 11;
	t.day = 30;

	md.TS_day = 1;

	IncreaseValue(&md, &t);

	EXPECT_EQ(t.day, 1);
}

// 202011299 박지인
TEST(IncreaseValueSuite, IncreaseValueTest6) {
	static MODE md;
	static TIME t;

	t.year = 2013;
	t.month = 12;
	t.day = 30;

	md.TS_day = 1;

	IncreaseValue(&md, &t);

	EXPECT_EQ(t.day, 31);
}

// 202011299 박지인
TEST(RecordLapTimeSuite, RecordLapTimeTest1) {
	static STOPWATCH sw;
	static MODE md;

	for (int csec = 0; csec < 100; csec += 10)
	{
		sw.C_second = csec;
		for (int sec = 0; sec < 60; sec += 6)
		{
			sw.second = sec;
			for (int min = 0; min < 100; min += 10)
			{
				sw.minute = min;

				RecordLapTime(&sw, &md);

				EXPECT_EQ(md.LAP_ON, 1);
				EXPECT_EQ(sw.Lap_Cse, sw.C_second);
				EXPECT_EQ(sw.Lap_se, sw.second);
				EXPECT_EQ(sw.Lap_min, sw.minute);
			}
		}
	}
}

// 202011299 박지인
TEST(StopwatchResetSuite, StopwatchResetTest1) {
	static STOPWATCH sw;

	for (int csec = 0; csec < 100; csec += 10)
	{
		sw.C_second = csec;
		for (int sec = 0; sec < 60; sec += 6)
		{
			sw.second = sec;
			for (int min = 0; min < 100; min += 10)
			{
				sw.minute = min;

				StopwatchReset(&sw);

				EXPECT_EQ(sw.C_second, 0);
				EXPECT_EQ(sw.second, 0);
				EXPECT_EQ(sw.minute, 0);
			}
		}
	}
}

// 202011299 박지인
TEST(LightControlSuite, LightControlTest1) {
	// button_info: !4
	// CHECK_ALARM: 0
	static MODE md;
	static ALARM r;
	int button_info = 0;

	for (int i = 1; i <= 4; i++)
	{
		button_info = i % 4;

		r.CHECK_ALARM = 0;

		LightControl(button_info, &md, &r);

		EXPECT_EQ(md.LIGHT_STATE, 0);
	}
}

// 202011299 박지인
TEST(LightControlSuite, LightControlTest2) {
	// button_info: 4
	// CHECK_ALARM: 0
	static MODE md;
	static ALARM r;
	int button_info = 0;

	button_info = 4;

	r.CHECK_ALARM = 0;

	LightControl(button_info, &md, &r);

	EXPECT_EQ(md.LIGHT_STATE, 1);
}

// 202011299 박지인
TEST(LightControlSuite, LightControlTest3) {	// 2초후 라이트 꺼지는지 확인
	// button_info: !4
	// CHECK_ALARM: 0
	static MODE md;
	static ALARM r;
	int button_info = 0;

	r.CHECK_ALARM = 0;

	LightControl(button_info, &md, &r);

	for (int i = 0; i < 200; i++)
	{
		button_info = i % 4;

		md.LIGHT_STATE = 1;

		r.CHECK_ALARM = 0;

		LightControl(button_info, &md, &r);

	}

	EXPECT_EQ(md.LIGHT_STATE, 0);	
}

// 202011299 박지인
TEST(LightControlSuite, LightControlTest4) {	// 라이트 유지 되는지 확인
	// button_info: 4
	// CHECK_ALARM: 0
	static MODE md;
	static ALARM r;
	int button_info = 0;

	button_info = 4;

	r.CHECK_ALARM = 0;

	LightControl(button_info, &md, &r);

	for (int i = 0; i < 200; i++)
	{
		button_info = 4;

		r.CHECK_ALARM = 0;

		LightControl(button_info, &md, &r);
	}

	EXPECT_EQ(md.LIGHT_STATE, 1);	
}

// 202011299 박지인
TEST(LightControlSuite, LightControlTest5) {	// 2초뒤 라이트 꺼지는지 확인
	// button_info: !4
	// CHECK_ALARM: 1
	static MODE md;
	static ALARM r;
	int button_info = 0;

	button_info = 4;

	r.CHECK_ALARM = 0;

	LightControl(button_info, &md, &r);

	for (int i = 0; i < 200; i++)
	{
		button_info = i % 4;

		r.CHECK_ALARM = 1;

		LightControl(button_info, &md, &r);

	}

	EXPECT_EQ(md.LIGHT_STATE, 0);	
}

// 202011299 박지인
TEST(LightControlSuite, LightControlTest6) {	// 2초뒤 라이트 꺼지는지 확인
	// button_info: 4
	// CHECK_ALARM: 1
	static MODE md;
	static ALARM r;
	int button_info = 0;

	button_info = 4;

	r.CHECK_ALARM = 0;

	LightControl(button_info, &md, &r);

	for (int i = 0; i < 200; i++)
	{
		button_info = 4;

		r.CHECK_ALARM = 1;

		LightControl(button_info, &md, &r);

	}

	EXPECT_EQ(md.LIGHT_STATE, 0);	
}

// 202011299 박지인
TEST(SwitchSectionAlarmSuite, SwitchSectionAlarmTest1) {
	static MODE md;

	md.M_ALS = 1;

	md.AL_hour = 1;
	md.AL_minute = 0;
	md.AL_month = 0;
	md.AL_day = 0;

	SwitchSectionAlarm(&md);

	EXPECT_EQ(md.AL_hour, 0);
	EXPECT_EQ(md.AL_minute, 1);
	EXPECT_EQ(md.AL_month, 0);
	EXPECT_EQ(md.AL_day, 0);
}

// 202011299 박지인
TEST(SwitchSectionAlarmSuite, SwitchSectionAlarmTest2) {
	static MODE md;

	md.M_ALS = 1;

	md.AL_hour = 0;
	md.AL_minute = 1;
	md.AL_month = 0;
	md.AL_day = 0;

	SwitchSectionAlarm(&md);

	EXPECT_EQ(md.AL_hour, 0);
	EXPECT_EQ(md.AL_minute, 0);
	EXPECT_EQ(md.AL_month, 1);
	EXPECT_EQ(md.AL_day, 0);
}

// 202011299 박지인
TEST(SwitchSectionAlarmSuite, SwitchSectionAlarmTest3) {
	static MODE md;

	md.M_ALS = 1;

	md.AL_hour = 0;
	md.AL_minute = 0;
	md.AL_month = 1;
	md.AL_day = 0;

	SwitchSectionAlarm(&md);

	EXPECT_EQ(md.AL_hour, 0);
	EXPECT_EQ(md.AL_minute, 0);
	EXPECT_EQ(md.AL_month, 0);
	EXPECT_EQ(md.AL_day, 1);
}

// 202011299 박지인
TEST(SwitchSectionAlarmSuite, SwitchSectionAlarmTest4) {
	static MODE md;

	md.M_ALS = 1;

	md.AL_hour = 0;
	md.AL_minute = 0;
	md.AL_month = 0;
	md.AL_day = 1;

	SwitchSectionAlarm(&md);

	EXPECT_EQ(md.AL_hour, 1);
	EXPECT_EQ(md.AL_minute, 0);
	EXPECT_EQ(md.AL_month, 0);
	EXPECT_EQ(md.AL_day, 0);
}

// 202011299 박지인
TEST(SwitchSectionSuite, SwitchSectionTest1) {
	static MODE md;
	
	md.M_TS = 1;

	md.TS_second = 1;
	md.TS_hour = 0;
	md.TS_minute = 0;
	md.TS_year = 0;
	md.TS_month = 0;
	md.TS_day = 0;

	SwitchSection(&md);
	
	EXPECT_EQ(md.TS_second, 0);
	EXPECT_EQ(md.TS_hour, 1);
	EXPECT_EQ(md.TS_minute, 0);
	EXPECT_EQ(md.TS_year, 0);
	EXPECT_EQ(md.TS_month, 0);
	EXPECT_EQ(md.TS_day, 0);	
}

// 202011299 박지인
TEST(SwitchSectionSuite, SwitchSectionTest2) {
	static MODE md;
	md.M_TS = 1;

	md.TS_second = 0;
	md.TS_hour = 1;
	md.TS_minute = 0;
	md.TS_year = 0;
	md.TS_month = 0;
	md.TS_day = 0;

	SwitchSection(&md);

	EXPECT_EQ(md.TS_second, 0);
	EXPECT_EQ(md.TS_hour, 0);
	EXPECT_EQ(md.TS_minute, 1);
	EXPECT_EQ(md.TS_year, 0);
	EXPECT_EQ(md.TS_month, 0);
	EXPECT_EQ(md.TS_day, 0);
}

// 202011299 박지인
TEST(SwitchSectionSuite, SwitchSectionTest3) {
	static MODE md;
	md.M_TS = 1;

	md.TS_second = 0;
	md.TS_hour = 0;
	md.TS_minute = 1;
	md.TS_year = 0;
	md.TS_month = 0;
	md.TS_day = 0;

	SwitchSection(&md);

	EXPECT_EQ(md.TS_second, 0);
	EXPECT_EQ(md.TS_hour, 0);
	EXPECT_EQ(md.TS_minute, 0);
	EXPECT_EQ(md.TS_year, 1);
	EXPECT_EQ(md.TS_month, 0);
	EXPECT_EQ(md.TS_day, 0);
}

// 202011299 박지인
TEST(SwitchSectionSuite, SwitchSectionTest4) {
	static MODE md;
	md.M_TS = 1;

	md.TS_second = 0;
	md.TS_hour = 0;
	md.TS_minute = 0;
	md.TS_year = 1;
	md.TS_month = 0;
	md.TS_day = 0;

	SwitchSection(&md);

	EXPECT_EQ(md.TS_second, 0);
	EXPECT_EQ(md.TS_hour, 0);
	EXPECT_EQ(md.TS_minute, 0);
	EXPECT_EQ(md.TS_year, 0);
	EXPECT_EQ(md.TS_month, 1);
	EXPECT_EQ(md.TS_day, 0);
}

// 202011299 박지인
TEST(SwitchSectionSuite, SwitchSectionTest5) {
	static MODE md;
	md.M_TS = 1;

	md.TS_second = 0;
	md.TS_hour = 0;
	md.TS_minute = 0;
	md.TS_year = 0;
	md.TS_month = 1;
	md.TS_day = 0;

	SwitchSection(&md);

	EXPECT_EQ(md.TS_second, 0);
	EXPECT_EQ(md.TS_hour, 0);
	EXPECT_EQ(md.TS_minute, 0);
	EXPECT_EQ(md.TS_year, 0);
	EXPECT_EQ(md.TS_month, 0);
	EXPECT_EQ(md.TS_day, 1);
}

// 202011299 박지인
TEST(SwitchSectionSuite, SwitchSectionTest6) {
	static MODE md;
	md.M_TS = 1;

	md.TS_second = 0;
	md.TS_hour = 0;
	md.TS_minute = 0;
	md.TS_year = 0;
	md.TS_month = 0;
	md.TS_day = 1;

	SwitchSection(&md);

	EXPECT_EQ(md.TS_second, 1);
	EXPECT_EQ(md.TS_hour, 0);
	EXPECT_EQ(md.TS_minute, 0);
	EXPECT_EQ(md.TS_year, 0);
	EXPECT_EQ(md.TS_month, 0);
	EXPECT_EQ(md.TS_day, 0);
}