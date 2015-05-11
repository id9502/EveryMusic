#ifndef TIMBRE
#define TIMBRE

namespace MIDI{
	enum Timbre{
		Acoustic_Grand_Piano,        //大钢琴（声学钢琴）
		Bright_Acoustic_Piano,        //明亮的钢琴
		Electric_Grand_Piano,        //电钢琴
		Honky_tonk_Piano,        //酒吧钢琴
		Rhodes_Piano,        //柔和的电钢琴
		Chorused_Piano,        //加合唱效果的电钢琴
		Harpsichord,        //羽管键琴（拨弦古钢琴）
		Clavichord,        //科拉维科特琴（击弦古钢琴）

		//色彩打击乐器
		Celesta,        //钢片琴
		Glockenspiel,        //钟琴
		Music_box,        //八音盒
		Vibraphone,        //颤音琴
		Marimba,        //马林巴
		Xylophone,        //木琴
		Tubular_Bells,        //管钟
		Dulcimer,        //大扬琴

		//风琴
		Hammond_Organ,        //击杆风琴
		Percussive_Organ,        //打击式风琴
		Rock_Organ,        //摇滚风琴
		Church_Organ,        //教堂风琴
		Reed_Organ,        //簧管风琴
		Accordian,        //手风琴
		Harmonica,        //口琴
		Tango_Accordian,        //探戈手风琴

		//吉他
		Acoustic_Guitar_nylon,        //尼龙弦吉他
		Acoustic_Guitar_steel,        //钢弦吉他
		Electric_Guitar_jazz,        //爵士电吉他
		Electric_Guitar_clean,        //清音电吉他
		Electric_Guitar_muted,        //闷音电吉他
		Overdriven_Guitar,        //加驱动效果的电吉他
		Distortion_Guitar,        //加失真效果的电吉他
		Guitar_Harmonics,        //吉他和音

		//贝司
		Acoustic_Bass,        //大贝司（声学贝司）
		Electric_Bass_finger,        //电贝司（指弹）
		Electric_Bass_pick,        //电贝司（拨片）
		Fretless_Bass,        //无品贝司
		Slap_Bass_1,        //掌击Bass 1
		Slap_Bass_2,        //掌击Bass 2
		Synth_Bass_1,        //电子合成Bass 1
		Synth_Bass_2,        //电子合成Bass 2

		//弦乐
		Violin,        //小提琴
		Viola,        //中提琴
		Cello,        //大提琴
		Contrabass,        //低音大提琴
		Tremolo_Strings,        //弦乐群颤音音色
		Pizzicato_Strings,        //弦乐群拨弦音色
		Orchestral_Harp,        //竖琴
		Timpani,        //定音鼓

		//合奏/合唱
		String_Ensemble_1,        //弦乐合奏音色1
		String_Ensemble_2,        //弦乐合奏音色2
		Synth_Strings_1,        //合成弦乐合奏音色1
		Synth_Strings_2,        //合成弦乐合奏音色2
		Choir_Aahs,        //人声合唱“啊”
		Voice_Oohs,        //人声“嘟”
		Synth_Voice,        //合成人声
		Orchestra_Hit,        //管弦乐敲击齐奏

		//铜管
		Trumpet,        //小号
		Trombone,        //长号
		Tuba,        //大号
		Muted_Trumpet,        //加弱音器小号
		French_Horn,        //法国号（圆号）
		Brass_Section,        //铜管组（铜管乐器合奏音色）
		Synth_Brass_1,        //合成铜管音色1
		Synth_Brass_2,        //合成铜管音色2

		//簧管
		Soprano_Sax,        //高音萨克斯风
		Alto_Sax,        //次中音萨克斯风
		Tenor_Sax,        //中音萨克斯风
		Baritone_Sax,        //低音萨克斯风
		Oboe,        //双簧管
		English_Horn,        //英国管
		Bassoon,        //巴松（大管）
		Clarinet,        //单簧管（黑管）

		//笛
		Piccolo,        //短笛
		Flute,        //长笛
		Recorder,        //竖笛
		Pan_Flute,        //排箫
		Bottle_Blow,        //吹瓶子
		Shakuhachi,        //日本尺八
		Whistle,        //口哨声
		Ocarina,        //奥卡雷那

		//合成主音
		Lead_1_square,        //合成主音1（方波）
		Lead_2_sawtooth,        //合成主音2（锯齿波）
		Lead_3_caliope_lead,        //合成主音3
		Lead_4_chiff_lead,        //合成主音4
		Lead_5_charang,        //合成主音5
		Lead_6_voice,        //合成主音6（人声）
		Lead_7_fifths,        //合成主音7（平行五度）
		Lead_8_bass_and_lead,        //合成主音8（贝司加主音）

		//合成音色
		Pad_1_new_age,        //合成音色1（新世纪）
		Pad_2_warm,        //合成音色2 （温暖）
		Pad_3_polysynth,        //合成音色3
		Pad_4_choir,        //合成音色4 （合唱）
		Pad_5_bowed,        //合成音色5
		Pad_6_metallic,        //合成音色6 （金属声）
		Pad_7_halo,        //合成音色7 （光环）
		Pad_8_sweep,        //合成音色8

		//合成效果
		FX_1_rain,        //合成效果 1 雨声
		FX_2_soundtrack,        //合成效果 2 音轨
		FX_3_crystal,        //合成效果 3 水晶
		FX_4_atmosphere,        //合成效果 4 大气
		FX_5_brightness,        //合成效果 5 明亮
		FX_6_goblins,        //合成效果 6 鬼怪
		FX_7_echoes,        //合成效果 7 回声
		FX_8_sci_fi,        //合成效果 8 科幻

		//民间乐器
		Sitar,        //西塔尔（印度）
		Banjo,        //班卓琴（美洲）
		Shamisen,        //三昧线（日本）
		Koto,        //十三弦筝（日本）
		Kalimba,        //卡林巴
		Bagpipe,        //风笛
		Fiddle,        //民族提琴
		Shanai,        //山奈

		//打击乐器
		Tinkle_Bell,        //叮当铃
		Agogo,        //高音撞铃
		Steel_Drums,        //钢鼓
		Woodblock,        //木鱼
		Taiko_Drum,        //太鼓
		Melodic_Tom,        //通通鼓
		Synth_Drum,        //合成鼓
		Reverse_Cymbal,        //铜钹

		//Sound Effects 声音效果
		Guitar_Fret_Noise,        //吉他换把杂音
		Breath_Noise,        //呼吸声
		Seashore,        //海浪声
		Bird_Tweet,        //鸟鸣
		Telephone_Ring,        //电话铃
		Helicopter,        //直升机
		Applause,        //鼓掌声
		Gunshot,        //枪击
	};
}




#endif // TIMBRE

