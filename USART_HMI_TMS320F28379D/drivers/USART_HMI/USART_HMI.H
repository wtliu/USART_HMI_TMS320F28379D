/*
 * USART_HMI.H
 */

#ifndef USART_HMI_H_
#define USART_HMI_H_



/*命令结束符号*/
#define USART_HMI_CMD_FORMAT_END   0xFF
/*返回命令起始字节*/
/*无效指令：0x00+结束符
 *指令执行成功：0x01+结束符
 *控件ID无效：0x02+结束符
 *页面ID无效：0x03+结束符
 *图片ID无效：0x04+结束符
 *字库ID无效：0x05+结束符
 *波特率设置无效：0x11+结束符
 *曲线控件ID号或通道号无效：0x12+结束符
 *变量名称无效：0x1A+结束符
 *变量运算无效：0x1B+结束符
 *赋值操作失败：0x1C+结束符
 *EEPROM操作失败：0x1D+结束符
 *参数数据无效：0x1E+结束符
 *IO操作失败：0x1F+结束符
 *转义字符使用错误：0x20+结束符
 * */
#define USART_HMI_CMD_INVALID               0x00
#define USART_HMI_CMD_SUCCESS               0x01
#define USART_HMI_CMD_CONTROLS_ID_INVALID   0x02
#define USART_HMI_CMD_PAGE_ID_INVALID       0x03
#define USART_HMI_CMD_IMAGE_ID_INVALID      0x04
#define USART_HMI_CMD_FONT_ID_INVALID       0x05
#define USART_HMI_CMD_SET_BAUD_INVALID      0x11
#define USART_HMI_CMD_CURVE_ID_INVALID      0x12
#define USART_HMI_CMD_VALUE_NAME_INVALID    0x1A
#define USART_HMI_CMD_VALUE_MATH_INVALID    0x1B
#define USART_HMI_CMD_SET_VALUE_ERROR       0x1C
#define USART_HMI_CMD_EEPROM_ERROR          0x1D
#define USART_HMI_CMD_VALUE_ERROR           0x1E
#define USART_HMI_CMD_IO_ERROR              0x1F
#define USART_HMI_CMD_STA_ERROR             0x20
/*
 * 触摸热区事件返回:
 * 0X65+页面 ID+按键 ID+触摸事件+结束符
 * (此事件需要在控件中勾选了发送键值)
 */
#define USART_HMI_CMD_TOUCH_EVENT           0x65
/*
 * 当前页面的 ID 号返回:
 * 0X66+页面 ID+结束符
 * (设备收到”sendme”指令时会返回此数据)
 */
#define USART_HMI_CMD_PAGE_ID               0x66
/*
 * 触摸坐标数据返回:
 * 0X67++坐标 X 高位+坐标 X 低位+坐标 Y 高位+坐标 Y 低位+触摸
 * 事件状态+结束符
 * (当系统变量” sendxy”为 1 之后，有触摸事件时返回此数据 )
 * (触摸事件的定义：按下事件 0x01 弹起事件 0X00)
 */
#define USART_HMI_CMD_TOUCH_XY              0x67
/*
 * 睡眠模式触摸事件:
 * 0X68++坐标 X 高位+坐标 X 低位+坐标 Y 高位+坐标 Y 低位+触摸
 * 事件状态+结束符
 *(当设备进入睡眠模式后 ，有触摸事件时返回此数据 )
 *(触摸事件的定义：按下事件 0x01 弹起事件 0X00)
 */
#define USART_HMI_CMD_SLEEP_TOUCH_XY        0x68
/*
 * 字符串变量数据返回:
 * 0X70+变量内容 ASCII 码+结束符
 * (使用 get 指令获取的变量为字符串类型时，返回此数据)
 */
#define USART_HMI_CMD_GET_STR             0x70
/*
 * 数值变量数据返回:
 * 0X71+变量二进制数据（4 字节小端模式,低位在前）+结束符
 * (使用 get 指令获取的变量为数值时，返回此数据)
 */
#define USART_HMI_CMD_GET_DATA            0x71
/*
 *设备自动进入睡眠模式:
 *0x86+结束符
 *只有设备自动进入睡眠模式的时候会返回此数据，如果是执行
 *串口指令 sleep=1 进入的睡眠不会返回此数据.
 */
#define USART_HMI_CMD_AUTO_SLEEP          0x86
/*
 * 设备自动唤醒:
 * 0x87+结束符
 * 只有设备自动唤醒的时候会返回此数据，如果是执行串口指令
 * sleep=0 唤醒的睡眠不会返回此数据
 */
#define USART_HMI_CMD_AUTO_WAKE           0x87
/*
 * 系统启动成功:
 * 0x88+结束符
 * 设备上电初始化成功之后发送此数据
 */
#define USART_HMI_CMD_INIT_SUCCESS        0x88
/*
 * 开始 SD 卡升级:
 * 0x89+结束符
 * 设备上电检测到 SD 卡之后将发送此数据,然后进入升级界面
 */
#define USART_HMI_CMD_SD_UPDATA           0x89
/*
 * 透传数据完成:
 * 0xFD+结束符
 * 透传数据结束并处理数据完成后发送此数据
 */
#define USART_HMI_CMD_DATA_UP_END         0xFD
/*
 * 数据透传就绪:
 * 0xFE+结束符
 * 设备收到数据透传指令后，进入透传数据初始化，初始化完成
 * 以后发送此数据，表示此时已经进入数据透传模式，可以开始
 * 数据透传
 */
#define USART_HMI_CMD_DATA_UP             0xFE

/*HMI颜色代号*/
#define USART_HMI_RED            63488 //红色
#define USART_HMI_BLUE              31 //蓝色
#define USART_HMI_GRAY           33840 //灰色
#define USART_HMI_BLOCK              0 //黑色
#define USART_HMI_WHITE          65535 //白色
#define USART_HMI_GREEN           2016 //绿色
#define USART_HMI_BROWN          48192 //橙色
#define USART_HMI_YELLOW         65504 //黄色
/*背光亮度*/
#define  USART_HMI_BACKLIGHT_MIN   0    //最小背光亮度
#define  USART_HMI_BACKLIGHT_MAX   100  //最大背光亮度
/*波特率*/
#define USART_HMI_BOAD_2400        2400
#define USART_HMI_BOAD_4800        4800
#define USART_HMI_BOAD_9600        9600
#define USART_HMI_BOAD_19200      19200
#define USART_HMI_BOAD_38400      38400
#define USART_HMI_BOAD_57600      57600
#define USART_HMI_BOAD_115200    115200
/*触摸绘图功能开关*/
#define USART_HMI_TOUCH_GRAPH_ON      1 //打开
#define USART_HMI_TOUCH_GRAPH_OFF     0 //关闭
/*触摸自动唤醒功能开关*/
#define USART_HMI_TOUCH_WAKE_ON       1 //打开
#define USART_HMI_TOUCH_WAKE_OFF      0 //关闭
/*指令返回模式*/
#define USART_HMI_CMD_NO_BACK         0 //无返回
#define USART_HMI_CMD_SUCCESS_BACK    1 //执行成功返回
#define USART_HMI_CMD_FAIL_BACK       2 //执行失败返回
#define USART_HMI_CMD_ALL_BACK        3 //都返回
/*实时发送触摸坐标功能开关*/
#define USART_HMI_SEND_XY_ON          1 //打开
#define USART_HMI_SEND_XY_OFF         0 //关闭
/*休眠*/
#define USART_HMI_SLEEP_ON            1 //打开
#define USART_HMI_SLEEP_OFF           0 //关闭
/*系统变量*/
typedef struct HMI_SYSTEM_DATA{
uint16_t dim;//背光亮度
uint16_t dims;//上电默认背光亮度
uint32_t band;//当前波特率
uint32_t bands;//上电默认波特率
uint16_t spax;//字体显示横向间距(上电默认为 0)
uint16_t spay;//字体显示纵向间距(上电默认为 0)
uint16_t thc;//触摸绘图时的画笔色
uint16_t thdra;//触摸绘图功能开关
uint16_t ussp;//无串口数据自动睡眠时间
uint16_t thsp;//无触摸操作自动睡眠时间
uint16_t thup;//睡眠模式下触摸自动唤醒开关
uint16_t bkcmd;//设置串口指令执行成功或者失败的数据返回
uint16_t sendxy;//实时发送触摸坐标功能开关
uint16_t delay;//延时
uint16_t sleep;//休眠
uint16_t rand;//随机数
int32_t  sys[3];//内置数值变量
uint16_t rtc[6];//RTC 时钟变量
bool     pio[8];//扩展 IO 端口
uint16_t pwm[4];//PWM输出占空比
uint16_t pwmf;//PWM输出频率
}hmi_system_data;
/*page结构*/
#endif /* USART_HMI_H_ */
