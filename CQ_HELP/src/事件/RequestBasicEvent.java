/*
 * Copyright (C) 2018 qq794
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

/**
 * 请求事件基类. 
 * @author MikuPy2001
 */
public abstract class RequestBasicEvent implements BasicEvent {

    /**
     * 发送时间(时间戳)
     */
    public int sendTime; // 发送时间(时间戳)
    /**
     * 来源QQ
     */
    public long fromQQ; // 来源QQ
    /**
     * 附言
     */
    public string msg; // 附言
    /**
     * 反馈标识(处理请求用)
     */
    public string responseFlag;// 反馈标识(处理请求用)

    /**
     * 通过此请求
     *
     * @param msg 好友备注
     * @see 酷Q.API#setGroupAddRequest(c.string, int, int, c.string)
     * @see 酷Q.API#setFriendAddRequest(c.string, int, c.string)
     *
     */
    public abstract void pass(string msg //= ""
    );

    /**
     * 拒绝此请求
     *
     * @param msg 拒绝理由 默认为"您由于不满足某些要求被拒绝!"
     * @see 酷Q.API#setGroupAddRequest(c.string, int, int, c.string)
     * @see 酷Q.API#setFriendAddRequest(c.string, int, c.string)
     */
    public abstract void fail(string msg //= "您由于不满足某些要求被拒绝!"
    );

}
