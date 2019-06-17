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
package 信息;

import c.string;
import c.unsigned_char;
import c.vector;
import 工具.Unpack;

/**
 * 群成员信息
 *
 * @author MikuPy2001
 */
public class GroupMemberInfo {

    public long Group;
    public long QQID;
    public string 昵称;
    public string 名片;
    /**
     * 0/男性 1/女性
     */
    public int 性别;
    public int 年龄;
    public string 地区;
    public int 加群时间;
    public int 最后发言;
    public string 等级_名称;
    /**
     * 1/成员 2/管理员 3/群主
     */
    public int permissions;
    public string 专属头衔;
    /**
     * 单位为秒, -1 代表不过期
     */
    public int 专属头衔过期时间;
    public boolean 不良记录成员;
    public boolean 允许修改名片;

    /**
     * 从Unpack解码
     *
     * @param msg 1
     */
    public GroupMemberInfo(Unpack msg) {
    }

    /**
     * 从API解码
     *
     * @param msg 1
     */
    public GroupMemberInfo(string msg) {
    }

    /**
     * 从Unpack解码
     *
     * @param msg 1
     */
    public GroupMemberInfo(vector< unsigned_char> msg) {
    }

    /**
     * 可视化
     *
     * @return 返回本对象的可读格式
     */
    @Override
    public String toString() {
        return super.toString();
    }
}
