//此类用于定义音频信息相关的全局函数
#pragma once
#include "Time.h"

//音频文件类型
enum AudioType
{
	AU_MP3,
	AU_WMA,
	AU_OGG,
	AU_MP4,
	AU_APE,
	AU_FLAC,
	AU_CUE,
	AU_OTHER
};

//排序方式
enum SortMode
{
	SM_FILE,
	SM_TITLE,
	SM_ARTIST,
	SM_ALBUM,
	SM_TRACK
};

//一首歌曲的信息
struct SongInfo
{
	wstring file_name{};	//歌曲的文件名
	wstring lyric_file{};	//匹配的歌词文件的路径
	Time lengh;			//歌曲的长度
	int bitrate{};		//比特率
	wstring title{ DEFAULT_TITLE };		//标题
	wstring artist{ DEFAULT_ARTIST };	//艺术家
	wstring album{ DEFAULT_ALBUM };		//唱片集
	wstring year{ DEFAULT_YEAR };		//年份
	wstring comment;	//注释
	wstring genre{ DEFAULT_GENRE };		//流派
	BYTE genre_idx{ 255 };		//以字节表示的流派号
	BYTE track{};		//音轨序号
	int tag_type{};		//标签的类型（0：其他；1：ID3v1；2：ID3v2）
	bool info_acquired{ false };		//如果已经获取到了信息，则为ture
	Time start_pos{};		//音频的起始位置，用于cue分轨
	Time end_pos{};
	bool is_cue{ false };		//如果曲目是cue分轨，则为true
	//wstring album_cover{};		//专辑封面保存的文件名

	//根据文件名的比较函数，用于以文件名排序
	static bool ByFileName(const SongInfo& a, const SongInfo& b) { return a.file_name < b.file_name; }
	//根据标题的比较函数，用于以标题排序
	static bool ByTitle(const SongInfo& a, const SongInfo& b) { return a.title < b.title; }
	//根据艺术家的比较函数，用于以艺术家排序
	static bool ByArtist(const SongInfo& a, const SongInfo& b) { return a.artist < b.artist; }
	//根据唱片集的比较函数，用于以唱片集排序
	static bool ByAlbum(const SongInfo& a, const SongInfo& b) { return a.album < b.album; }
	//根据音轨序号的比较函数，用于以音轨序号排序
	static bool ByTrack(const SongInfo& a, const SongInfo& b) { return a.track < b.track; }
};


// ID3v1 tag structure
struct TAG_ID3V1
{
	char id[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[28];
	BYTE track[2];
	BYTE genre;
};

//储存路径信息
struct PathInfo
{
	wstring path;		//路径
	int track{};			//最后播放到的曲目号
	int position{};		//最后播放到的位置
	SortMode sort_mode{};	//路径中文件的排序方式
	int track_num{};		//路径中音频文件的数量
	int total_time{};		//路径中音频文件的总时间

	//PathInfo(wstring _path, int _track, int _position, SortMode _sort_mode) :
	//	path{ _path }, track{ _track }, position{ _position }, sort_mode{ _sort_mode }
	//{}
};

//循环模式
enum RepeatMode
{
	RM_PLAY_ORDER,		//顺序播放
	RM_PLAY_SHUFFLE,	//随机播放
	RM_LOOP_PLAYLIST,	//列表循环
	RM_LOOP_TRACK		//单曲循环
};

//播放列表中项目的显示格式
enum DisplayFormat
{
	DF_FILE_NAME,		//文件名
	DF_TITLE,			//标题
	DF_ARTIST_TITLE,	//艺术家 - 标题
	DF_TITLE_ARTIST		//标题 - 艺术家
};

#define GENRE_MAX 148
//流派列表
const wchar_t GENRE_TABLE[GENRE_MAX][24]
{
	L"Blues",
	L"ClassicRock",
	L"Country",
	L"Dance",
	L"Disco",
	L"Funk",
	L"Grunge",
	L"Hip-Hop",
	L"Jazz",
	L"Metal",
	L"NewAge",
	L"Oldies",
	L"Other",
	L"Pop",
	L"R&B",
	L"Rap",
	L"Reggae",
	L"Rock",
	L"Techno",
	L"Industrial",
	L"Alternative",
	L"Ska",
	L"DeathMetal",
	L"Pranks",
	L"Soundtrack",
	L"Euro-Techno",
	L"Ambient",
	L"Trip-Hop",
	L"Vocal",
	L"Jazz+Funk",
	L"Fusion",
	L"Trance",
	L"Classical",
	L"Instrumental",
	L"Acid",
	L"House",
	L"Game",
	L"SoundClip",
	L"Gospel",
	L"Noise",
	L"AlternRock",
	L"Bass",
	L"Soul",
	L"Punk",
	L"Space",
	L"Meditative",
	L"InstrumentalPop",
	L"InstrumentalRock",
	L"Ethnic",
	L"Gothic",
	L"Darkwave",
	L"Techno-Industrial",
	L"Electronic",
	L"Pop-Folk",
	L"Eurodance",
	L"Dream",
	L"SouthernRock",
	L"Comedy",
	L"Cult",
	L"Gangsta",
	L"Top40",
	L"ChristianRap",
	L"Pop/Funk",
	L"Jungle",
	L"NativeAmerican",
	L"Cabaret",
	L"NewWave",
	L"Psychadelic",
	L"Rave",
	L"Showtunes",
	L"Trailer",
	L"Lo-Fi",
	L"Tribal",
	L"AcidPunk",
	L"AcidJazz",
	L"Polka",
	L"Retro",
	L"Musical",
	L"Rock&Roll",
	L"HardRock",
	L"Folk",
	L"Folk-Rock",
	L"NationalFolk",
	L"Swing",
	L"FastFusion",
	L"Bebob",
	L"Latin",
	L"Revival",
	L"Celtic",
	L"Bluegrass",
	L"Avantgarde",
	L"GothicRock",
	L"ProgessiveRock",
	L"PsychedelicRock",
	L"SymphonicRock",
	L"SlowRock",
	L"BigBand",
	L"Chorus",
	L"EasyListening",
	L"Acoustic",
	L"Humour",
	L"Speech",
	L"Chanson",
	L"Opera",
	L"ChamberMusic",
	L"Sonata",
	L"Symphony",
	L"BootyBass",
	L"Primus",
	L"PornGroove",
	L"Satire",
	L"SlowJam",
	L"Club",
	L"Tango",
	L"Samba",
	L"Folklore",
	L"Ballad",
	L"PowerBallad",
	L"RhythmicSoul",
	L"Freestyle",
	L"Duet",
	L"PunkRock",
	L"DrumSolo",
	L"Acapella",
	L"Euro-House",
	L"DanceHall",
	L"Goa",
	L"Drum&Bass",
	L"Club-House",
	L"Hardcore",
	L"Terror",
	L"Indie",
	L"BritPop",
	L"Negerpunk",
	L"PolskPunk",
	L"Beat",
	L"ChristianGangstaRap",
	L"HeavyMetal",
	L"BlackMetal",
	L"Crossover",
	L"ContemporaryChristian",
	L"ChristianRock",
	L"Merengue",
	L"Salsa",
	L"TrashMetal",
	L"Anime",
	L"JPop",
	L"Synthpop",
};

class CAudioCommon
{
public:
	CAudioCommon();
	~CAudioCommon();

	//判断文件类型是否为音频文件
	static bool FileIsAudio(const wstring& file_name);

	//根据文件名判断文件的类型
	static AudioType GetAudioType(const wstring& file_name);

	//查找path目录下的所有音频文件，并将文件名保存到files容器中，并限定最大文件数为max_file
	static void GetAudioFiles(wstring path, vector<SongInfo>& files, size_t max_file);

	//查找path目录下的所有歌词文件，并将文件名保存到files容器中
	static void GetLyricFiles(wstring path, vector<wstring>& files);

	//处理files容器中的cue文件，并将每段分轨作为一个曲目添加到files容器中，path为文件的路径
	static void GetCueTracks(vector<SongInfo>& files, wstring path);

	//检查files容器中是否有和cue文件匹配的音频文件，如果没有，则重新从路径中查找匹配的音频文件
	static void CheckCueFiles(vector<SongInfo>& files, wstring path);

	//获取音频文件的信息，并储存在song_info中（file_path在获取flac格式时用到）
	static void GetAudioTags(HSTREAM hStream, AudioType type, wstring file_path, SongInfo& song_info);

	//获取音频文件的专辑封面，并保存到临时目录，返回保存路径，image_type用来接收封面的格式 0:jpg, 1:png, 2:gif
	static wstring GetAlbumCover(HSTREAM hStream, int& image_type);
	static wstring GetFlacAlbumCover(const wstring& file_name, int& image_type);

	//向一个MP3文件写入ID3V1标签，如果写入的文本长度超过ID3V1可容纳的长度，则过长的文本将会被截断，并将text_cut_off置为true
	static bool WriteMp3Tag(LPCTSTR file_name, const SongInfo& song_info, bool& text_cut_off);

	//获得标准流派信息
	static wstring GetGenre(BYTE genre);

	////删除字符串末尾的空格
	//static void DeleteEndSpace(wstring& str);

	//删除一个字符串中非打印字符开始的后面全部字符
	static void TagStrNormalize(wstring& str);

protected:
	//获取FLAC音频的标签区域的内容
	static void GetFlacTagContents(wstring file_name, string& contents_buff);

	static wstring _GetAlbumCover(const string& tag_content, size_t cover_index, int& image_type);

};

