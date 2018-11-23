/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package 枚举;

/**
 *
 * @author admin
 */
public enum Log_ {
    /**
     * 调试       灰色
     */
    Log_Debug(0),
    /**
     * 信息       黑色
     */
    Log_Info(10),
    /**
     * 信息(成功) 紫色
     */
    Log_InfoSuccess(11),
    /**
     * 信息(接收) 蓝色
     */
    Log_InfoRecv(12),
    /**
     * 信息(发送) 绿色
     */
    Log_InfoSend(13),
    /**
     * 警告       橙色
     */
    Log_Warning(20),
    /**
     * 错误       红色
     */
    Log_Error(30),
    /**
     * 致命错误   深红
     */
    Log_Fatal(40);
    
    private Log_(int i) {
    }
}
