#pragma once
#include <list>
#include <vector>
#include "../json/json.h"
#include "../xml/tinyxml2.h"
#include <afxinet.h>
//#include <string>
//using namespace std;

// struct define degin
// �ַ������ʽ��Ϊutf8
typedef struct tagServiceInfo {
	std::string ip;
	unsigned int port;
} ServiceInfo;

typedef struct tagSchoolBaseInfo {
	std::string school_id;
	std::string school_name;
	std::string school_code;
	int school_level;
	int school_type;
	int school_state;
	std::string create_time;  // "2017/4/19 14:27:35"
} SchoolBaseInfo;

typedef struct tagCameraInfo {
	std::string cam_id;
	std::string camName;
	int cam_type;  // 1-�󻪣�2-������3-�ɼ���
				   // ��� CamType Ϊ 1��2:
				   // ��ʽΪ��IP|�˿�|�����˺�|��������|ͨ���š���
				   // ��� CamType Ϊ3:
				   // ��ʽΪ����ض���1��ѧ�� 2������ 3����Ļ��|���Һ�|¼��������IP��ַ��
	std::string set_info;
	double resolution_width;
	double resolution_height;
	std::string error_flag;

	tagCameraInfo& operator=(const tagCameraInfo& other) {
		cam_id = other.cam_id;
		camName = other.camName;
		cam_type = other.cam_type;
		set_info = other.set_info;
		resolution_width = other.resolution_width;
		resolution_height = other.resolution_height;
		error_flag = other.error_flag;
		return *this;
	}
} CameraInfo;

typedef struct tagCamera{
	
	// ��ʽΪ��IP|�˿�|�����˺�|��������|ͨ���š���
	std::string camera_ip;
	std::string camera_port;
	std::string camera_username;
	std::string camera_userpwd;
	std::string camera_ch;

	tagCamera& operator=(const tagCamera& other) {
		camera_ip = other.camera_ip;
		camera_port	= other.camera_port;
		camera_username = other.camera_username;
		camera_userpwd = other.camera_userpwd;
		camera_ch = other.camera_ch;
		return *this;
	}
} Camera;

typedef struct tagNoElcRoomCamInfo
{
    std::string cam_id;
    int cam_type;
    std::string camName;
    std::string camIP;
    std::string camPort;
    std::string camAccount;
    std::string camPwd;
    tagNoElcRoomCamInfo& operator=(const tagNoElcRoomCamInfo& other)
    {
        cam_id = other.cam_id;
        cam_type = other.cam_type;
        camName = other.camName;
        camIP = other.camIP;
        camPort = other.camPort;
        camAccount = other.camAccount;
        camPwd = other.camPwd;
        return *this;
    }
}NoElcRoomCamInfo;

typedef struct TagSecurityCamServers
{
    int id;
    int type;
    std::string ip;
    std::string port;
    TagSecurityCamServers& operator=(const TagSecurityCamServers& other)
    {
        id = other.id;
        type = other.type;
        ip = other.ip;
        port = other.port;
        return *this;
    }
}SecurityCamServers;
typedef struct TagSecurityCamInfo
{
    int cam_id;
    int cam_brand;
    std::string camName;
    std::string camIP;
    std::string camPort;
    std::string camAccount;
    std::string camPwd;
    std::string camPostion;
    std::list<SecurityCamServers> cam_servers;
    TagSecurityCamInfo& operator=(const TagSecurityCamInfo& other)
    {
        cam_id = other.cam_id;
        cam_brand = other.cam_brand;
        camName = other.camName;
        camIP = other.camIP;
        camPort = other.camPort;
        camAccount = other.camAccount;
        camPwd = other.camPwd;
        camPostion = other.camPostion;
        cam_servers = other.cam_servers;
        return *this;
    }
}SecurityCamInfo;

typedef struct tagIP {

	// ��ʽΪ��IP|�˿�|�����˺�|��������|ͨ���š���
	std::string strRtmp_ip;
	std::string str480_ip;
	std::string str1080_ip;
	std::string strCmb_ip;

	tagIP& operator=(const tagIP& other) {
		strRtmp_ip = other.strRtmp_ip;
		str480_ip = other.str480_ip;
		str1080_ip = other.str1080_ip;
		strCmb_ip = other.strCmb_ip;
		return *this;
	}
} IP;

typedef struct tagDeviceInfo {
	std::string amplifier_model_id;  // �����豸�ͺ�
	std::string dvd_model_id;        // DVD �豸�ͺ�
	std::string projector_model_id;  // ͶӰ���豸�ͺ�
	std::string lamplight_model_id;  // �ƹ��豸�ͺ�
	std::string curtain_model_id;    // �����豸�ͺ�

	tagDeviceInfo& operator=(const tagDeviceInfo& other) {
		amplifier_model_id = other.amplifier_model_id;
		dvd_model_id = other.dvd_model_id;
		projector_model_id = other.projector_model_id;
		lamplight_model_id = other.lamplight_model_id;
		curtain_model_id = other.curtain_model_id;
		return *this;
	}
} DeviceInfo;

typedef struct tagBigScreenmodel {
	int id;
	double position_x;
	double position_y;
	double width;
	double height;
	int classroom_id;
	std::string update_time;  // "2017-04-26T14:24:00"
	double resolution_width;
	double resolution_height;

	tagBigScreenmodel& operator=(const tagBigScreenmodel& other) {
		id = other.id;
		position_x = other.position_x;
		position_y = other.position_y;
		width = other.width;
		height = other.height;
		classroom_id = other.classroom_id;
		update_time = other.update_time;
		resolution_width = other.resolution_width;
		resolution_height = other.resolution_height;
		return *this;
	}
} BigScreenmodel;

typedef struct tagElectricClassroomInfo {
	int roomId;
	std::string roomName;
	std::string roomPwd;
	std::string buildingName;
	std::string rPersonName;
	std::string rPersonPhone;
	std::string roomStatus;  //����״̬ 0Ϊ������1Ϊ����
	std::string hostMac;
	std::string electricType; //1Ϊ��̬¼����2Ϊ��Ʒ¼��
	std::string roomVersion;  //�пؽ��Ұ汾
	std::string centralIp;
	int centralPort;
	std::string terminalIp;
	int terminalPort;
	std::string recordServerIp; //���Ϊ��Ʒ¼�����ң�¼����������ַ|��Ʒ¼����������ַ
	std::list<CameraInfo> camera_info_list;
	std::string deviceEquip; //�豸���ʶ����ʽΪ���ƹ�����|��������|ͶӰ��Ʒ�� ��������  3|2| Ĭ��Ʒ��

	tagElectricClassroomInfo& operator=(const tagElectricClassroomInfo& other) {
		roomId = other.roomId;
		roomName = other.roomName;
		roomPwd = other.roomPwd;
		buildingName = other.buildingName;
		rPersonName = other.rPersonName;
		rPersonPhone = other.rPersonPhone;
		roomStatus = other.roomStatus;
		hostMac = other.hostMac;
		electricType = other.electricType;
		roomVersion = other.roomVersion;
		centralIp = other.centralIp;
		centralPort = other.centralPort;
		terminalIp = other.terminalIp;
		terminalPort = other.terminalPort;
		recordServerIp = other.recordServerIp;
		camera_info_list = other.camera_info_list;
		deviceEquip = other.deviceEquip;
		return *this;
	}
}ElectricClassroomInfo;

typedef struct tagNoElectricClassroomInfo
{
    int roomId;
    int roomType;
    std::string roomName;
    std::string serverIP;
    std::list<NoElcRoomCamInfo> noElcRoomCam_list;
    tagNoElectricClassroomInfo& operator=(const tagNoElectricClassroomInfo& other) 
    {
        roomId = other.roomId;
        roomType = other.roomType;
        roomName = other.roomName;
        serverIP = other.serverIP;
        noElcRoomCam_list = other.noElcRoomCam_list;
        return *this;
    }
}NoElectricClassroomInfo;

typedef struct TagCampusSecurityInfo
{
    int id;
    std::string name;
    std::list<SecurityCamInfo> securCam_list;
    TagCampusSecurityInfo& operator=(const TagCampusSecurityInfo& other)
    {
        id = other.id;
        name = other.name;
        securCam_list = other.securCam_list;
        return *this;
    }
}CampusSecurityInfo;


//typedef struct tagElectricClassroomInfo {
//	int classroom_id;
//	std::string classroom_name;
//	std::string host_mac_addr;
//	std::string central_ip;
//	int central_port;
//	std::string terminal_iP;
//	int terminal_port;
//	std::string room_version;
//	std::string update_time;  // "2017-04-26T14:24:00"
//							  // ��ʽΪ�������䱸��ʶ|DVD�䱸��ʶ|ͶӰ���䱸��ʶ|�ƹ��䱸��ʶ|�����䱸��ʶ��
//							  // 1 ��ʾ���䱸��0 ��ʾ���䱸���磺1|0|1|0|0��
//	std::string device_equip_flag;
//	// ��ʽΪ�����Ź��ϱ�ʶ|DVD���ϱ�ʶ|ͶӰ�ǹ��ϱ�ʶ|�ƹ���ϱ�ʶ|�������ϱ�ʶ��//
//	// �磺1|0|1|0|0��
//	std::string device_error_flag;
//	std::string record_server_ip; // ¼��������ip, portд��9911
//	DeviceInfo device_info;
//	BigScreenmodel big_screenmodel_info;
//	std::list<CameraInfo> camera_info_list;
//
//	tagElectricClassroomInfo& operator=(const tagElectricClassroomInfo& other) {
//		classroom_id = other.classroom_id;
//		classroom_name = other.classroom_name;
//		host_mac_addr = other.host_mac_addr;
//		central_ip = other.central_ip;
//		central_port = other.central_port;
//		terminal_iP = other.terminal_iP;
//		terminal_port = other.terminal_port;
//		room_version = other.room_version;
//		update_time = other.update_time;
//		device_equip_flag = other.device_equip_flag;
//		device_error_flag = other.device_error_flag;
//		device_info = other.device_info;
//		big_screenmodel_info = other.big_screenmodel_info;
//		camera_info_list = other.camera_info_list;
//		return *this;
//	}
//} ElectricClassroomInfo;

typedef struct tagCamInfo {
	std::string camId;
	int cam_type;
	std::string cam_ip;
	int cam_port;
	std::string access_account;
	std::string access_pwd;
	int resolution_width;
	int resolution_height;
	int error_flag;

	tagCamInfo& operator=(const tagCamInfo& other) {
		camId = other.camId;
		cam_type = other.cam_type;
		cam_ip = other.cam_ip;
		cam_port = other.cam_port;
		access_account = other.access_account;
		access_pwd = other.access_pwd;
		resolution_width = other.resolution_width;
		resolution_height = other.resolution_height;
		error_flag = other.error_flag;
		return *this;
	}
} CamInfo;

typedef struct tagNetWorkRoomInfo {
	int room_id;
	std::string room_name;
	std::string teacher_ip;
	std::string mac_addr;
	std::list<CamInfo> cam_info_list;

	tagNetWorkRoomInfo& operator=(const tagNetWorkRoomInfo& other) {
		room_id = other.room_id;
		room_name = other.room_name;
		teacher_ip = other.teacher_ip;
		mac_addr = other.mac_addr;
		cam_info_list = other.cam_info_list;
		return *this;
	}
} NetWorkRoomInfo;

struct AbnormalInfo
{
	//std::string ServerID;
	// int  ServerNo;
	// std::string  ServerName;
	// std::string  ServerIP;
	// std::string  ServerPort;
	// std::string  VirtualDirName;
	// std::string  UserName;
	// std::string  UserPwd;
	// std::string  PhyPath;
	// std::string  MacAddr;
	// std::string  WANIP;
	// std::string  WANPort;

	std::string lanIp;
	int lanPort;
	std::string macAddr;
	std::string passWord;
	std::string phyPath;
	std::string userName;
	std::string virtualDirName;
	std::string wanIp;
	int wanPort;
	std::string websitName;
	int websitType;
};


class CBaseService
{
public:
	CBaseService();
	virtual ~CBaseService(void);

public:
	int ParseResponse(char* buf, Json::Value& json_data);
	void ConvertElement(tinyxml2::XMLElement* node, Json::Value& json_data, bool root_is_array);
	
	/********************************************
	** �������ƣ�Exp_GetSubSystemServerInfo
	** �������ã���ȡ�ӷ�������ip&port(ip:port)
	**
	** ��Σ�
	**  tcSysID��			�ӷ�����ID
	** ���Σ�
	**  tcIPandPort��		ip&port(ip:port)
	**
	** ����ֵ��
	**					   0 ִ�гɹ�
	**					  -1 ִ��ʧ��
	**
	********************************************/
	long GetSubSystemServerInfo(IN char* tcSysID, OUT char* tcIPandPort);
	// ��ȡ��������Ϣ
	// @param ip ����ƽ̨������IP
	// @param port ����ƽ̨�������˿�
	// @param code ����������
	//              "D00" У԰�㲥������
	//              "890" �����ݷ�����
	//              "E00" ѧУ������Ϣ������
	// @param service_ip ��ȡ�ķ�����IP
	// @param service_port ��ȡ�ķ������˿�
	// @return 0:Succeeded 1:Failed
	int GetServiceInfo(IN char* cIP, IN char* port, IN char* code, OUT char* service_ip, OUT char* service_port);
	// ��ȡ��ǰѧУ������Ϣ
	// @param ip ����ƽ̨������IP
	// @param port ����ƽ̨�������˿�
	// @param school_info ѧУ������Ϣ
	// @return 0:Succeeded 1:Failed
	int GetCurrentSchoolInfo(IN char* ip, IN char* port,	OUT SchoolBaseInfo& school_info);

	// ��ȡ��ǰѧУ��ý�������б�
	// @param ip ����ƽ̨������IP
	// @param port ����ƽ̨�������˿�
	// @param classroom_list ��ý�������б�
	// @return 0:Succeeded 1:Failed
	int GetAllElectricClassroomInfo(IN char* ip, IN char* port, OUT std::list<ElectricClassroomInfo>& classroom_list);

	// ͨ������id��ȡ���� ��ý��������Ϣ
	// @param classroom_list ��ý�������б�
	// @param classroom_id ����id
	// @param classroom_info �õ��İ༶��Ϣ
	// @return 0:Succeeded 1:Failed
	int GetElectricClassroomInfoByClassID(IN std::list<ElectricClassroomInfo>& classroom_list, IN int classroom_id, OUT ElectricClassroomInfo& classroom_info);

	// ��ȡ��ǰѧУ����������б�
	// @param ip ����ƽ̨������IP
	// @param port ����ƽ̨�������˿�
	// @param classroom_list ����������б�
	// @return 0:Succeeded 1:Failed
	int GetAllNetClassroomInfo(IN char* ip, IN char* port,OUT std::list<NetWorkRoomInfo>& classroom_list);

	// ͨ������id��ȡ���������������Ϣ
	// @param classroom_list ����������б�
	// @param classroom_id ����id
	// @param classroom_info �õ��İ༶��Ϣ
	// @return 0:Succeeded 1:Failed
	int GetNetClassroomInfoByClassID(IN std::list<NetWorkRoomInfo>& classroom_list, IN int classroom_id,OUT NetWorkRoomInfo& classroom_info);
    int GetAllNoElectricRoomInfo(IN char* ip, IN char* port, OUT std::list<NoElectricClassroomInfo>& classroom_list);
    int GetAllCampusSecurityInfo(IN char* ip, IN char* port, OUT std::list<CampusSecurityInfo>& campusSecur_list);
	bool InsertStatusCtx(char* ip, char* port, struct AbnormalInfo temp);
private:
	std::string m_sReqData;
public:
	std::string m_strServerIP;
};

void  ResolveLine(std::string sMsg, Camera& stu_camera);
void  ResolveIPLine(std::string sMsg, IP& stu_ip);
void  Remorvespace(std::string& str);
