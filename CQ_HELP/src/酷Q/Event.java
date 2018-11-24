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
 * @author admin
 */
public interface Event {

    /**
     * 返回应用的ApiVer、Appid，打包后将不会调用.
     *
     * @param AppInfo
     * @return
     */
    string MUST_AppInfo(string AppInfo);

    /**
     * 返回应用的ApiVer、Appid，打包后将不会调用. {@link #MUST_AppInfo(c.string) }的简化版本.<p>
     * 例: MUST_AppInfo_RETURN("com.MikuPy2001.app")
     * <p>
     * 直接返回文本
     *
     * @param AppInfo
     * @return
     */
    string MUST_AppInfo_RETURN(string AppInfo);

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
     * 请固定返回 0.
     * <p>
     * <p>
     * 名字如果使用下划线开头需要改成双下划线.
     *
     * @return
     */
    int EVE_Startup();

    /**
     * 酷Q退出(Type=1002)
     * <p>
     * 本子程序会在酷Q【主线程】中被调用。
     * <p>
     * 无论本应用是否被启用，本函数都会在酷Q退出前执行一次，请在这里执行插件关闭代码。
     * <p>
     * 本函数调用完毕后，酷Q将很快关闭，请不要再通过线程等方式执行其他代码。
     * <p>
     * 名字如果使用下划线开头需要改成双下划线。
     * <p>
     * 返回非零值,消息将被拦截,最高优先不可拦截。
     * <p>
     * @return
     */
    int EVE_Exit();

    /*
应用已被启用(Type=1003)

当应用被启用后，将收到此事件。
如果酷Q载入时应用已被启用，则在 EVE_Startup(Type=1001,酷Q启动) 被调用后，本函数也将被调用一次。
如非必要，不建议在这里加载窗口。（可以添加菜单，让用户手动打开窗口）

名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 应用已被启用(Type=1003)
     *
     * @return
     */
    int EVE_Enable();

    /*
     * 应用将被停用(Type=1004)
     *
     * 当应用被停用前，将收到此事件。 如果酷Q载入时应用已被停用，则本函数【不会】被调用。 无论本应用是否被启用，酷Q关闭前本函数都【不会】被调用。
     *
     * 名字如果使用下划线开头需要改成双下划线 返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 应用将被停用(Type=1004)
     *
     * @return
     */
    int EVE_Disable();

    /*
私聊消息(Type=21)

此函数具有以下参数
subType		子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
msgId		消息ID
fromQQ		来源QQ
msg			消息内容
font		字体

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 私聊消息(Type=21)
     *
     * @param subType
     * @param msgId
     * @param fromQQ
     * @param msg
     * @param font
     * @return
     */
    消息_ EVE_PrivateMsg(int subType, int msgId, long fromQQ, string msg, int font);

    /*
     * 私聊消息(Type=21)
     *
     * 此函数具有以下参数 subType	子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组 msgId	消息ID fromQQ
     * 来源QQ msg	私聊消息 font	字体
     *
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
     * 名字如果使用下划线开头需要改成双下划线 返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 私聊消息(Type=21)
     *
     * @param e
     */
    void EVE_PrivateMsg_EX(PrivateMsgEvent e);


    /*
群消息(Type=2)

subType		子类型，目前固定为1
msgId		消息ID
fromGroup	来源群号
fromQQ		来源QQ号
fromAnonymous 来源匿名者
msg			消息内容
font		字体

如果消息来自匿名者,fromQQ 固定为 80000000,可使用工具将 fromAnonymous 转换为 匿名者信息

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 群消息(Type=2)
     *
     * @param subType
     * @param msgId
     * @param fromGroup
     * @param fromQQ
     * @param fromAnonymous
     * @param msg
     * @param font
     * @return
     */
    消息_ EVE_GroupMsg(int subType, int msgId, long fromGroup, long fromQQ, string fromAnonymous, string msg, int font);

    /*
群消息(Type=2)

subType 子类型，目前固定为1
msgId 消息ID
fromGroup 来源群号
fromQQ 来源QQ号
fromAnonymous 来源匿名者
msg 消息内容
font 字体

如果消息来自匿名者,isAnonymous; 返回 true, 可使用 getFromAnonymousInfo; 获取 匿名者信息

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 群消息(Type=2)
     *
     * @param e
     */
    void EVE_GroupMsg_EX(GroupMsgEvent e);


    /*
讨论组消息(Type=4)

subtype		子类型，目前固定为1
msgId		消息ID
fromDiscuss	来源讨论组
fromQQ		来源QQ号
msg			消息内容
font		字体

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 讨论组消息(Type=4)
     *
     * @param subType
     * @param msgId
     * @param fromDiscuss
     * @param fromQQ
     * @param msg
     * @param font
     * @return
     */
    消息_ EVE_DiscussMsg(int subType, int msgId, long fromDiscuss, long fromQQ, string msg, int font);

    /*
讨论组消息(Type=4)

subtype		子类型，目前固定为1
msgId		消息ID
fromDiscuss	来源讨论组
fromQQ		来源QQ号
msg			消息内容
font		字体

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 讨论组消息(Type=4)
     *
     * @param e
     */
    void EVE_DiscussMsg_EX(DiscussMsgEvent e);

    /*
群文件上传事件(Type=11)

subType 子类型，目前固定为1
sendTime 发送时间(时间戳)
fromGroup 来源群号
fromQQ 来源QQ号
file 上传文件信息,使用 <其他_转换_文本到群文件> 将本参数转换为有效数据,待编辑

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 群文件上传事件(Type=11)
     *
     * @param subType
     * @param sendTime
     * @param fromGroup
     * @param fromQQ
     * @param file
     * @return
     */
    消息_ EVE_GroupUpload(int subType, int sendTime, long fromGroup, long fromQQ, string file);

    /*
群事件-管理员变动(Type=101)

subtype			子类型，1/被取消管理员 2/被设置管理员
sendTime 发送时间(时间戳)
fromGroup		来源群号
beingOperateQQ	被操作QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 群事件-管理员变动(Type=101)
     *
     * @param subType
     * @param sendTime
     * @param fromGroup
     * @param beingOperateQQ
     * @return
     */
    消息_ EVE_System_GroupAdmin(int subType, int sendTime, long fromGroup, long beingOperateQQ);

    /*
群事件-管理员变动(Type=101)

subtype			子类型，1/被取消管理员 2/被设置管理员
sendTime 发送时间(时间戳)
fromGroup		来源群号
beingOperateQQ	被操作QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 群事件-管理员变动(Type=101)
     *
     * @param e
     */
    void EVE_System_GroupAdmin_EX(SystemGroupAdminEvent e);

    /*
群事件-群成员减少(Type=102)

subtype		子类型，1/群员离开 2/群员被踢 3/自己(即登录号)被踢
sendTime 发送时间(时间戳)
fromGroup	来源群号
fromQQ		操作者QQ(仅子类型为2、3时存在)
beingOperateQQ 被操作QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 群事件-群成员减少(Type=102)
     *
     * @param subType
     * @param sendTime
     * @param fromGroup
     * @param fromQQ
     * @param beingOperateQQ
     * @return
     */
    消息_ EVE_System_GroupMemberDecrease(int subType, int sendTime, long fromGroup, long fromQQ, long beingOperateQQ);

    /*
群事件-群成员增加(Type=103)

subtype 子类型，1/管理员已同意 2/管理员邀请
sendTime 发送时间(时间戳)
fromGroup 来源群号
fromQQ 操作者QQ(即管理员QQ)
beingOperateQQ 被操作QQ(即加群的QQ)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 群事件-群成员增加(Type=103)
     *
     * @param subType
     * @param sendTime
     * @param fromGroup
     * @param fromQQ
     * @param beingOperateQQ
     * @return
     */
    消息_ EVE_System_GroupMemberIncrease(int subType, int sendTime, long fromGroup, long fromQQ, long beingOperateQQ);

    /*
好友事件-好友已添加(Type=201)

subtype 子类型，目前固定为1
sendTime 发送时间(时间戳)
fromQQ 来源QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 好友事件-好友已添加(Type=201)
     *
     * @param subType
     * @param sendTime
     * @param fromQQ
     * @return
     */
    消息_ EVE_Friend_Add(int subType, int sendTime, long fromQQ);

    /*
好友事件-好友已添加(Type=201)

subtype 子类型，目前固定为1
msgId 消息ID
fromQQ 来源QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 好友事件-好友已添加(Type=201)
     *
     * @param e
     */
    void EVE_Friend_Add_EX(FriendAddEvent e);

    /*
请求-好友添加(Type=301)

subtype 子类型，目前固定为1
sendTime 发送时间(时间戳)
fromQQ 来源QQ
msg 附言
responseFlag 反馈标识(处理请求用)

置好友添加请求 (responseFlag, #请求_通过)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 请求-好友添加(Type=301)
     *
     * @param subType
     * @param sendTime
     * @param fromQQ
     * @param msg
     * @param responseFlag
     * @return
     */
    消息_ EVE_Request_AddFriend(int subType, int sendTime, long fromQQ, string msg, string responseFlag);

    /*
请求-好友添加(Type=301)

subtype 子类型，目前固定为1
sendTime 发送时间(时间戳)
fromQQ 来源QQ
msg 附言
responseFlag 反馈标识(处理请求用)

置好友添加请求 (responseFlag, #请求_通过)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     * 请求-好友添加(Type=301)
     *
     * @param e
     */
    void EVE_Request_AddFriend_EX(RequestAddFriendEvent e);

    /*
请求-群添加(Type=302)

subtype 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
sendTime 发送时间(时间戳)
fromGroup 来源群号
fromQQ 来源QQ
msg 附言
responseFlag 反馈标识(处理请求用)

如果 subtype ＝ 1
置群添加请求 (responseFlag, #请求_群添加, #请求_通过)
如果 subtype ＝ 2
置群添加请求 (responseFlag, #请求_群邀请, #请求_通过)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     *
     * @param subType
     * @param sendTime
     * @param fromGroup
     * @param fromQQ
     * @param msg
     * @param responseFlag
     * @return
     */
    消息_ EVE_Request_AddGroup(int subType, int sendTime, long fromGroup, long fromQQ, string msg, string responseFlag);

    /*
请求-群添加(Type=302)

subtype 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
sendTime 发送时间(时间戳)
fromGroup 来源群号
fromQQ 来源QQ
msg 附言
responseFlag 反馈标识(处理请求用)

如果 subtype ＝ 1
置群添加请求 (responseFlag, #请求_群添加, #请求_通过)
如果 subtype ＝ 2
置群添加请求 (responseFlag, #请求_群邀请, #请求_通过)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     *
     * @param e
     */
    void EVE_Request_AddGroup_EX(RequestAddGroupEvent e);

    /*
菜单

可在 .json 文件中设置菜单数目、函数名
如果不使用菜单，请在 .json 及此处删除无用菜单
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
     */
    /**
     *
     * @return
     */
    消息_ EVE_Menu();

    /*
悬浮窗

请使用EX版本
emmm,因为一些原因,悬浮窗暂时不可用...

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)。
名字如果使用下划线开头需要改成双下划线
     */
    /**
     *
     * @return
     */
    string EVE_Status();

    /*
悬浮窗

请设置 eve.data eve.dataf eve.color 其他函数保持不动即可

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)。
名字如果使用下划线开头需要改成双下划线
     */
    /**
     *
     * @param e
     */
    void EVE_Status_EX(StatusEvent e);

}
