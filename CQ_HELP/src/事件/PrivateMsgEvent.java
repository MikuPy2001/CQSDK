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

/**
 * 私聊事件. 好友/临时/陌生人 都算私聊
 * @author MikuPy2001
 */
public abstract class PrivateMsgEvent extends MsgEvent {

    /**
     * 来自好友
     *
     * @return 来自好友
     */
    public abstract boolean fromPrivate();

    /**
     * 来自在线状态
     *
     * @return 来自在线状态
     */
    public abstract boolean fromOnlineStatus();

    /**
     * 来自群临时
     *
     * @return 来自群临时
     */
    public abstract boolean fromGroup();

    /**
     * 来自讨论组临时
     *
     * @return 来自讨论组临时
     */
    public abstract boolean fromDiscuss();

}
