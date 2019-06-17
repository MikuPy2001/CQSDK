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
 * 请求-群添加
 * @author MikuPy2001
 */
public abstract class RequestAddGroupEvent extends RequestBasicEvent {

    /**
     * 子类型 1:他人申请入群 2:自己(即登录号)受邀入群
     */
    public int subType;
    /**
     * 来源群号
     */
    public long fromGroup;
}
