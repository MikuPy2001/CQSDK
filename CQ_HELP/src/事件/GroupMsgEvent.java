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
package 事件;

import c.string;
import c.vector;
import 信息.AnonymousInfo;
import 信息.GroupMemberInfo;

/**
 * 群聊事件
 * @author MikuPy2001
 */
public abstract class GroupMsgEvent extends MsgEvent {

    //群号
    public long fromGroup;
    //禁言用的令牌
    public string fromAnonymousToken;

    /**
     * 判断是否匿名
     *
     * @return 如果是匿名者发送的消息则返回真
     */
    public abstract boolean isAnonymous();

    /**
     * 获取匿名者信息
     *
     * @return 匿名者信息
     */
    public abstract AnonymousInfo getFromAnonymousInfo() /*throw(exception_ptr)*/;

    /**
     * 置群员移除
     *
     * @param refusedAddAgain 是否不再接收入群信息
     * @return 秘制返回
     * @see 酷Q.API#setGroupKick(long, long, boolean)
     */
    public abstract boolean setGroupKick(boolean refusedAddAgain);

    /**
     * 置群员禁言,自动判断是否是匿名.
     *
     * @param banTime 禁言时间,可省略,默认为60
     * @return 秘制返回
     * @see 酷Q.API#setGroupBan(long, long, long)
     * @see 酷Q.API#setGroupAnonymousBan(long, c.string, long)
     */
    public abstract boolean setGroupBan(long banTime);

    /**
     * 置群管理员
     *
     * @param isAdmin 可省略,默认为取消管理
     * @return 秘制返回
     * @see 酷Q.API#setGroupAdmin(long, long, boolean)
     */
    public abstract boolean setGroupAdmin(boolean isAdmin);

    /**
     * 置群成员专属头衔
     *
     * @param 专属头衔 专属头衔
     * @param 过期时间 单位(秒),可省略,默认永久(-1)
     * @return 秘制返回
     * @see 酷Q.API#setGroupSpecialTitle(long, long, c.string, long)
     */
    public abstract boolean setGroupSpecialTitle(string 专属头衔, long 过期时间);

    /**
     * 置全群禁言
     *
     * @param 开启禁言 可省略,默认为禁言,假为解禁
     * @return 秘制返回
     * @see 酷Q.API#setGroupWholeBan(long, boolean)
     */
    public abstract boolean setGroupWholeBan(boolean 开启禁言);

    /**
     * 置群匿名设置
     *
     * @param 开启匿名
     * @return 秘制返回
     * @see 酷Q.API#setGroupAnonymous(long, boolean)
     */
    public abstract boolean setGroupAnonymous(boolean 开启匿名);

    /**
     * 置群成员名片
     *
     * @param 新名片_昵称 新名片_昵称
     * @return 秘制返回
     * @see 酷Q.API#setGroupCard(long, long, c.string)
     */
    public abstract boolean setGroupCard(string 新名片_昵称);

    /**
     * 置群退出
     *
     * @param 是否解散 群主不可退出,退出既为解散群
     * @return 秘制返回
     * @see 酷Q.API#setGroupLeave(long, boolean)
     */
    public abstract boolean setGroupLeave(boolean 是否解散);

    /**
     * 取群成员信息 (默认使用缓存)
     *
     * @param 不使用缓存 强制获取最新信息,多次调用可能会冻结QQ,默认为假
     * @return 群成员信息
     * @see 酷Q.API#getGroupMemberInfo(long, long, boolean)
     */
    public abstract GroupMemberInfo getGroupMemberInfo(boolean 不使用缓存);

    /**
     * 取群成员列表
     *
     * @return 群成员列表
     * @see 酷Q.API#getGroupMemberList(long)
     */
    public abstract vector<GroupMemberInfo> getGroupMemberList();
}
