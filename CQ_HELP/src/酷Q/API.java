/*
 * Copyright (C) 2018 admin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package 酷Q;

import 信息.GroupMemberInfo;
import 信息.StrangerInfo;
import 枚举.Log_;
import c.vector;
import c.map;
import c.string;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author MikuPy2001
 */
public interface API {
    /**
     * 获取调用api所需的AuthCode. 一般情况不需要调用
     * @return AuthCode
     */
	int getAuthCode();

    /**
     * 增加运行日志
     *
     * @param 优先级 整数型.具体查看枚举,可以直接使用枚举名称
     * @param 类型 void
     * @param 内容 void
     * @return 秘制返回
     */
    int addLog(Log_ 优先级, string 类型, string 内容);

    /**
     * 置致命错误提示,暂时不知道干什么用的
     *
     * @param 错误信息 错误信息
     * @return 秘制返回
     */
    int setFatal(string 错误信息);

    /**
     * 发送好友消息 Auth=106, 失败返回负值,成功返回消息ID.
     *
     * @param QQ void
     * @param msg void
     * @return 失败返回负值,成功返回消息ID
     */
    int sendPrivateMsg(long QQ, string msg);

    /**
     * 发送群消息 Auth=101 失败返回负值,成功返回消息ID
     *
     * @param 群号 void
     * @param msg void
     * @return 失败返回负值,成功返回消息ID
     */
    int sendGroupMsg(long 群号, string msg);

    /**
     * 发送讨论组消息 Auth=103 失败返回负值,成功返回消息ID
     *
     * @param 讨论组号 讨论组号
     * @param msg 消息主体
     * @return 失败返回负值,成功返回消息ID
     */
    int sendDiscussMsg(long 讨论组号, string msg);

    /**
     * 发送赞 Auth=110
     *
     * @param QQID QQID
     * @param times 次数
     * @return void
     */
    int sendLike(long QQID, int times);

    /**
     * 取Cookies Auth=20 慎用,此接口需要严格授权
     *
     * @return Cookies
     */
    string getCookies();

    /**
     * 接收消息中的语音(record) Auth=30 返回保存在 \data\record\ 目录下的文件名 //getRecord
     *
     * @param file 收到消息中的语音文件名 (file)
     * @param outformat 应用所需的格式 mp3,amr,wma,m4a,spx,ogg,wav,flac
     * @return 文件名 文件位于(酷Q\data\record\)
     */
    string getRecord(
            string file, // 收到消息中的语音文件名 (file)
            string outformat // 应用所需的格式 mp3,amr,wma,m4a,spx,ogg,wav,flac
    );

    /**
     * 取CsrfToken (慎用，此接口需要严格授权) Auth=20 即QQ网页用到的bkn/g_tk等 慎用,此接口需要严格授权
     *
     * @return CsrfToken
     */
    int getCsrfToken();

    /**
     * 取应用目录,返回的路径末尾带"\"
     *
     * @return 应用目录
     */
    string getAppDirectory();

    /**
     * 取登录QQ
     *
     * @return 登录QQ
     */
    long getLoginQQ();

    /**
     * 取登录昵称
     *
     * @return 登录昵称
     */
    string getLoginNick();

    /**
     * 置群员移除 Auth=120
     *
     * @param 群号 群号
     * @param QQID QQID
     * @param 拒绝再加群 可以不填,默认为假,如果为真，则“不再接收此人加群申请”，请慎用
     * @return 秘制返回
     */
    int setGroupKick(
            long 群号, long QQID,
            boolean 拒绝再加群 //= false // 如果为真，则“不再接收此人加群申请”，请慎用
    );

    /**
     * 置群员禁言 Auth=121
     *
     * @param 群号 群号
     * @param QQID QQID
     * @param 禁言时间 可以不填,默认60秒,单位为秒。如果要解禁，这里填写0
     * @return 秘制返回
     */
    int setGroupBan(
            long 群号, long QQID,
            long 禁言时间 //= 60 // 禁言的时间，单位为秒。如果要解禁，这里填写0
    );

    /**
     * 置群管理员 Auth=122
     *
     * @param 群号 群号
     * @param QQID QQID
     * @param 成为管理员 默认为真,假为取消管理
     * @return 秘制返回
     */
    int setGroupAdmin(
            long 群号, long QQID,
            boolean 成为管理员 //= true // 真/设置管理员 假/取消管理员
    );

    /**
     * 置群成员专属头衔 Auth=128 需群主权限
     *
     * @param 群号 群号
     * @param QQID QQID
     * @param 头衔 如果要删除，这里填空
     * @param 有效期 默认为永久(-1),单位为秒。
     * @return 秘制返回
     */
    int setGroupSpecialTitle(
            long 群号, long QQID,
            string 头衔, // 如果要删除，这里填空
            long 有效期// = -1 // 专属头衔有效期，单位为秒。如果永久有效，这里填写-1
    );

    /**
     * 置全群禁言 Auth=123
     *
     * @param 群号 群号
     * @param 开启禁言 默认为真,假为解除禁言
     * @return 秘制返回
     */
    int setGroupWholeBan(
            long 群号,
            boolean 开启禁言 //= true // 真/开启 假/关闭
    );

    /**
     * 置匿名群员禁言 Auth=124
     *
     * @param 群号 群号
     * @param 匿名 群消息事件收到的“匿名”参数
     * @param 禁言时间 默认60秒,不支持解禁
     * @return 秘制返回
     */
    int setGroupAnonymousBan(
            long 群号,
            string 匿名, // 群消息事件收到的“匿名”参数
            long 禁言时间 //= 60 // 禁言的时间，单位为秒。不支持解禁
    );

    /**
     * 置群匿名设置 Auth=125
     *
     * @param 群号 群号
     * @param 开启匿名 真为开启,假为关闭
     * @return 秘制返回
     */
    int setGroupAnonymous(long 群号, boolean 开启匿名 //= true
    );

    /**
     * 置群成员名片 Auth=126
     *
     * @param 群号 群号
     * @param QQID QQID
     * @param 新名片_昵称 新名片_昵称
     * @return 秘制返回
     */
    int setGroupCard(long 群号, long QQID, string 新名片_昵称);

    /**
     * 置群退出 Auth=127 慎用,此接口需要严格授权
     *
     * @param 群号 群号
     * @param 是否解散 默认为假,真/解散本群 (群主),假/退出本群 (管理、群成员)
     * @return 秘制返回
     */
    int setGroupLeave(
            long 群号,
            boolean 是否解散 //= false // 真/解散本群 (群主) 假/退出本群 (管理、群成员)
    );

    /**
     * 置讨论组退出 Auth=140
     *
     * @param 讨论组号 讨论组号
     * @return 秘制返回
     */
    int setDiscussLeave(
            long 讨论组号
    );

    /**
     * 置好友添加请求 Auth=150
     *
     * @param 请求反馈标识 请求事件收到的“反馈标识”参数
     * @param 反馈类型 #请求_通过 或 #请求_拒绝
     * @param 备注 添加后的好友备注
     * @return 秘制返回
     */
    int setFriendAddRequest(
            string 请求反馈标识, // 请求事件收到的“反馈标识”参数
            int 反馈类型, // #请求_通过 或 #请求_拒绝
            string 备注 // 添加后的好友备注
    );

    /**
     * 置群添加请求 Auth=151
     *
     * @param 请求反馈标识 请求事件收到的“反馈标识”参数
     * @param 请求类型 根据请求事件的子类型区分 #请求_群添加 或 #请求_群邀请
     * @param 反馈类型 #请求_通过 或 #请求_拒绝
     * @param 理由 操作理由，仅 #请求_群添加 且 #请求_拒绝 时可用
     * @return 秘制返回
     */
    int setGroupAddRequest(
            string 请求反馈标识, // 请求事件收到的“反馈标识”参数
            int 请求类型, // 根据请求事件的子类型区分 #请求_群添加 或 #请求_群邀请
            int 反馈类型, // #请求_通过 或 #请求_拒绝
            string 理由 // 操作理由，仅 #请求_群添加 且 #请求_拒绝 时可用
    );

    /**
     * 取群成员信息 (支持缓存) Auth=130
     *
     * @param 群号 群号
     * @param QQID QQID
     * @param 不使用缓存 默认为假
     * @return 秘制返回
     */
    GroupMemberInfo getGroupMemberInfo(long 群号, long QQID, boolean 不使用缓存 //= false
    );

    /**
     * 取陌生人信息 (支持缓存) Auth=131
     *
     * @param QQID QQID
     * @param 不使用缓存 强制获取最新信息,多次调用可能会冻结QQ,默认为假
     * @return 陌生人信息
     */
    StrangerInfo getStrangerInfo(long QQID, boolean 不使用缓存 //= false
    );

    /**
     * 取群成员列表 Auth=160
     *
     * @param 群号 群号
     * @return 群成员列表
     */
    vector<GroupMemberInfo> getGroupMemberList(long 群号);

    /**
     * 取群列表 Auth=161
     *
     * @return Map[群号,群名称]
     */
    map<Long, string> getGroupList();

    /**
     * 撤回消息 Auth=180
     *
     * @param MsgId MsgId
     * @return 秘制返回
     */
    int deleteMsg(long MsgId);

    /**
     * 如果API调用返回错误代码, 则可以使用本函数获取相关中文信息
     *
     * @return 错误代码关联的中文信息
     */
    string getlasterrmsg();
}
