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
 * 群事件-管理员变动
 * @author MikuPy2001
 */
public abstract class SystemGroupAdminEvent implements BasicEvent {

    /**
     * 子类型，1 / 被取消管理员 2 / 被设置管理员
     */
    public int subType;
    /**
     * 发送时间(时间戳)
     */
    public int sendTime;
    /**
     * 来源群号
     */
    public long fromGroup;
    /**
     * 被操作QQ
     */
    public long beingOperateQQ;
}
