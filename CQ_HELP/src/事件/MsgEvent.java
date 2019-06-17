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
import 工具.MsgSend;

/**
 * 聊天事件基类. 实现一些聊天通用功能
 * @author MikuPy2001
 */
public abstract class MsgEvent implements BasicEvent {

    /**
     * 消息ID
     */
    public int msgId;
    /**
     * 消息ID
     */
    public long fromQQ;
    /**
     * 消息
     */
    public string message;
    public string messageRAW;

    /**
     * 是否真实用户
     *
     * @return 是否真实用户
     */
    public abstract boolean isUser();

    /**
     * 是否是系统用户
     *
     * @return 是否是系统用户
     */
    public abstract boolean isSystem();

    /**
     * 发送消息
     *
     * @param msg 发送消息
     * @return
     */
    public abstract int sendMsg(string msg);

    /**
     * 返回关联消息发送工具. 该工具自动绑定事件来源群或者私聊
     *
     * @return 返回关联消息发送工具
     */
    public abstract MsgSend sendMsg();
}
