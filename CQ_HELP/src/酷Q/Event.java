/*
Copyright (C) 2018 admin
 *
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
 *
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 *
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package 酷Q;

import c.string;
import 枚举.*;
import 事件.*;

/**
 *
 * @author MikuPy2001
 */
public interface Event {

    /**
     * 应用的ApiVer、Appid.
     * <p>
     * 请不要在本子程序添加其他代码
     *
     * @return 返回格式为: "ApiVer,AppID"
     */
    string MUST_AppInfo();

    /**
     * 返回应用的ApiVer、Appid，打包后将不会调用.
     * <p>
     * {@link 酷Q.Event#MUST_AppInfo() }的简化版本.
     * <p>
     * 例: MUST_AppInfo_RETURN("com.MikuPy2001.app")
     * <p>
     * 直接返回文本
     *
     * @return 自动返回相应文本
     * @see 酷Q.Event#MUST_AppInfo()
     */
    string MUST_AppInfo_RETURN();

    /**
     * 酷Q启动事件(Type=1001).
     *
     * <p>
     * 本子程序会在酷Q【主线程】中被调用。
     * <p>
     * 无论本应用是否被启用，本函数都会在酷Q启动后执行一次，请在这里执行插件初始化代码。
     * <p>
     * 请务必尽快返回本子程序，否则会卡住其他插件以及主程序的加载。
     * <p>
     * 名字如果使用下划线开头需要改成双下划线.
     *
     * @return 请固定返回 0.
     */
    int EVE_Startup();

    /**
     * 酷Q退出(Type=1002).
     * <p>
     * 本子程序会在酷Q【主线程】中被调用。
     * <p>
     * 无论本应用是否被启用，本函数都会在酷Q退出前执行一次，请在这里执行插件关闭代码。
     * <p>
     * 名字如果使用下划线开头需要改成双下划线。
     *
     * @return 请固定返回0，返回后酷Q将很快关闭，请不要再通过线程等方式执行其他代码。
     */
    int EVE_Exit();

    /**
     * 应用已被启用(Type=1003).
     * <p>
     * 当应用被启用后，将收到此事件。
     * <p>
     * 如果酷Q载入时应用已被启用，则在 EVE_Startup(Type=1001,酷Q启动) 被调用后，本函数也将被调用一次。
     * <p>
     * 如非必要，不建议在这里加载窗口。（可以添加菜单，让用户手动打开窗口）
     * <p>
     * 名字如果使用下划线开头需要改成双下划线。
     *
     * @return 请固定返回0。
     */
    int EVE_Enable();

    /**
     * 应用将被停用(Type=1004).
     * <p>
     * 当应用被停用前，将收到此事件。
     * <p>
     * 如果酷Q载入时应用已被停用，则本函数【不会】被调用。
     * <p>
     * 无论本应用是否被启用，酷Q关闭前本函数都【不会】被调用。
     *
     * @return 请固定返回0。
     */
    int EVE_Disable();

    /**
     * 私聊消息(Type=21).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
     * @param msgId 消息ID
     * @param fromQQ 来源QQ
     * @param msg 消息内容
     * @param font 此参数现在已经废弃
     * @return 返回规定参考值.
     */
    是否拦截 EVE_PrivateMsg(int subType, int msgId, long fromQQ, string msg, int font);


    /**
     * 群消息(Type=2).
     * <p>
     * 如果消息来自匿名者,fromQQ 固定为 80000000,可使用工具将 fromAnonymous 转换为 匿名者信息
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，目前固定为1
     * @param msgId 消息ID
     * @param fromGroup 来源群号
     * @param fromQQ 来源QQ号
     * @param fromAnonymous 来源匿名者
     * @param msg 消息内容
     * @param font 此参数现在已经废弃
     * @return 返回规定参考值.
     */
    是否拦截 EVE_GroupMsg(int subType, int msgId, long fromGroup, long fromQQ, string fromAnonymous, string msg, int font);


    /**
     * 讨论组消息(Type=4).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，目前固定为1
     * @param msgId 消息ID
     * @param fromDiscuss 来源讨论组
     * @param fromQQ 来源QQ号
     * @param msg 消息内容
     * @param font 此参数现在已经废弃
     * @return 返回规定参考值.
     */
    是否拦截 EVE_DiscussMsg(int subType, int msgId, long fromDiscuss, long fromQQ, string msg, int font);


    /**
     * 群文件上传事件(Type=11).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，目前固定为1
     * @param sendTime 发送时间(时间戳)
     * @param fromGroup 来源群号
     * @param fromQQ 来源QQ号
     * @param file 上传文件信息,需要转换为有效数据.
     * @return 返回规定参考值.
     */
    是否拦截 EVE_GroupUpload(int subType, int sendTime, long fromGroup, long fromQQ, string file);

    /**
     * 群事件-管理员变动(Type=101).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，1/被取消管理员 2/被设置管理员
     * @param sendTime 发送时间(时间戳)
     * @param fromGroup 来源群号
     * @param beingOperateQQ 被操作QQ
     * @return 返回规定参考值.
     */
    是否拦截 EVE_System_GroupAdmin(int subType, int sendTime, long fromGroup, long beingOperateQQ);


    /**
     * 群事件-群成员减少(Type=102).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，1/群员离开 2/群员被踢 3/自己(即登录号)被踢
     * @param sendTime 发送时间(时间戳)
     * @param fromGroup 来源群号
     * @param fromQQ 操作者QQ(仅子类型为2、3时存在)
     * @param beingOperateQQ 被操作QQ
     * @return 返回规定参考值.
     */
    是否拦截 EVE_System_GroupMemberDecrease(int subType, int sendTime, long fromGroup, long fromQQ, long beingOperateQQ);

    /**
     * 群事件-群成员增加(Type=103).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，1/管理员已同意 2/管理员邀请
     * @param sendTime 发送时间(时间戳)
     * @param fromGroup 来源群号
     * @param fromQQ 操作者QQ(即管理员QQ)
     * @param beingOperateQQ 被操作QQ(即加群的QQ)
     * @return 返回规定参考值.
     */
    是否拦截 EVE_System_GroupMemberIncrease(int subType, int sendTime, long fromGroup, long fromQQ, long beingOperateQQ);

    /**
     * 好友事件-好友已添加(Type=201).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，目前固定为1
     * @param sendTime 发送时间(时间戳)
     * @param fromQQ 来源QQ
     * @return 返回规定参考值.
     */
    是否拦截 EVE_Friend_Add(int subType, int sendTime, long fromQQ);


    /**
     * 请求-好友添加(Type=301).
     * 如果要通过请求或者拒绝请求请查看相应函数
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，目前固定为1
     * @param sendTime 发送时间(时间戳)
     * @param fromQQ 来源QQ
     * @param msg 附言
     * @param responseFlag 反馈标识(处理请求用)
     * @return 返回规定参考值.
     * @see 酷Q.API#setFriendAddRequest(c.string, int, c.string)
     */
    是否拦截 EVE_Request_AddFriend(int subType, int sendTime, long fromQQ, string msg, string responseFlag);


    /**
     * 请求-群添加(Type=302).
     * <p>
     * 如果 subtype ＝ 1
     * <p>
     * setGroupAddRequest (responseFlag, #请求_群添加, #请求_通过, 一些拒绝的理由)
     * <p>
     * 如果 subtype ＝ 2
     * <p>
     * setGroupAddRequest (responseFlag, #请求_群邀请, #请求_通过, 一些拒绝的理由)
     *
     *
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param subType 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
     * @param sendTime 发送时间(时间戳)
     * @param fromGroup 来源群号
     * @param fromQQ 来源QQ
     * @param msg 附言
     * @param responseFlag 反馈标识(处理请求用)
     * @return 返回规定参考值.
     * @see 酷Q.API#setGroupAddRequest(c.string, int, int, c.string)
     */
    是否拦截 EVE_Request_AddGroup(int subType, int sendTime, long fromGroup, long fromQQ, string msg, string responseFlag);


    /**
     * 菜单.
     * <p>
     * 可在 .json 文件中设置菜单数目、函数名
     * <p>
     * 如果不使用菜单，请在 .json 及此处删除无用菜单
     * <p>
     * 本子程序会在酷Q【主线程】中被调用。
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @return 固定返回0.
     */
    是否拦截 EVE_Menu();

    /**
     * 悬浮窗.
     * <p>
     * 请务必使用EX版本.
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @return base64_encode(Unpack.add(数据).add(数据单位).add(颜色).getAll());
     */
    string EVE_Status();

}
