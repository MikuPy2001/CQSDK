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

import 事件.*;

/**
 *
 * @author MikuPy2001
 */
public interface EventEx extends Event {

    /**
     * 私聊消息(Type=21).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param e 事件对象
     */
    void EVE_PrivateMsg_EX(PrivateMsgEvent e);

    /**
     * 群消息(Type=2).
     * <p>
     * 如果消息来自匿名者,isAnonymous() 返回 true, 可使用 getFromAnonymousInfo() 获取 匿名者信息
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param e 事件对象
     * @see 事件.GroupMsgEvent#isAnonymous()
     * @see 事件.GroupMsgEvent#getFromAnonymousInfo()
     * @see 信息.AnonymousInfo
     */
    void EVE_GroupMsg_EX(GroupMsgEvent e);

    /**
     * 讨论组消息(Type=4).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param e 事件对象
     */
    void EVE_DiscussMsg_EX(DiscussMsgEvent e);

    /**
     * 群事件-管理员变动(Type=101).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param e 事件对象
     */
    void EVE_System_GroupAdmin_EX(SystemGroupAdminEvent e);

    /**
     * 好友事件-好友已添加(Type=201).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param e 事件对象
     */
    void EVE_Friend_Add_EX(FriendAddEvent e);

    /**
     * 请求-好友添加(Type=301).
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param e 事件对象
     */
    void EVE_Request_AddFriend_EX(RequestAddFriendEvent e);

    /**
     * 请求-群添加(Type=302).
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param e 事件对象
     */
    void EVE_Request_AddGroup_EX(RequestAddGroupEvent e);

    /**
     * 悬浮窗.
     * <p>
     * 请设置 e.data e.dataf e.color 其他函数保持不动即可
     * <p>
     * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
     * <p>
     * 名字如果使用下划线开头需要改成双下划线
     *
     * @param e 事件对象
     */
    void EVE_Status_EX(StatusEvent e);
}
