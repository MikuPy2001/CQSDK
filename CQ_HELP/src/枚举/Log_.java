/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package 枚举;

/**
 * 仅用于日志相关的函数
 * @author MikuPy2001
 */
public enum Log_ {
    /**
     * 调试 灰色 0
     */
    Log_Debug,
    /**
     * 信息 黑色 10
     */
    Log_Info,
    /**
     * 信息(成功) 紫色 11
     */
    Log_InfoSuccess,
    /**
     * 信息(接收) 蓝色 12
     */
    Log_InfoRecv,
    /**
     * 信息(发送) 绿色 13
     */
    Log_InfoSend,
    /**
     * 警告 橙色 20
     */
    Log_Warning,
    /**
     * 错误 红色 30
     */
    Log_Error,
    /**
     * 致命错误 深红 40
     */
    Log_Fatal;
}
