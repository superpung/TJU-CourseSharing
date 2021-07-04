/// <reference path="../Scripts/jquery-1.4.2-vsdoc.js" />
/*#region Init*/
$.ajaxSetup({
    type: 'post',
    dataType: 'json',
    contentType: 'application/json; charset=utf-8'
});
/*#endregion*/

/* #region common */
function OpenWindow(url, width, height, offset) {
    var leftVal = (screen.width - width) / 2 - offset;
    var topVal = (screen.height - height) / 2 - offset;
    var newwindow = window.open(url, '_blank', 'width=' + width + ',height=' + height + ',toolbars=0,resizable=1,left=' + leftVal + ',top=' + topVal);
    newwindow.focus();
}
/* #endregion */

var isSyntaxHighlighted = false;

function WarpClass(eID, tID, fID, ev) {
    var eObj = document.getElementById(eID);
    var tObj = document.getElementById(tID);
    var fObj = document.getElementById(fID);
    if (eObj && tObj) {
        if (!tObj.style.display || tObj.style.display == "block") {
            tObj.style.display = "none";
            eObj.className = "Warp";
            if (fObj) {
                fObj.style.display = "none";
            }
        }
        else {
            tObj.style.display = "block";
            eObj.className = "UnWarp";
            if (ev) {
                eval(ev);
            }
            if (fObj) {
                fObj.style.display = "block";
            }
        }
    }
}

function PutInWz() {
    var width = 480;
    var height = 360;
    var leftVal = (screen.width - width) / 2;
    var topVal = (screen.height - height) / 2;
    var d = document;
    var title = document.getElementsByTagName('title')[0].innerHTML;
    var t = d.selection ? (d.selection.type != 'None' ? d.selection.createRange().text : '') : (d.getSelection ? d.getSelection() : '');
    window.open('http://home.cnblogs.com/wz/create?t=' + encodeURIComponent(title) + '&u=' + encodeURIComponent(d.location.href) + '&c=' +
     encodeURIComponent(t) + '&i=0', '_blank', 'width=' + width + ',height=' + height + ',toolbars=0,resizable=1,left=' + leftVal + ',top=' + topVal);
}

function AddToWz(entryId) {
    var width = 480;
    var height = 360;
    var leftVal = (screen.width - width) / 2;
    var topVal = (screen.height - height) / 2;
    var d = document;
    var t = d.selection ? (d.selection.type != 'None' ? d.selection.createRange().text : '') : (d.getSelection ? d.getSelection() : '');

    var title = document.getElementsByTagName('title')[0].innerHTML;
    var url = 'http://home.cnblogs.com/wz/create?t=' + encodeURIComponent(title) + '&u=' + encodeURIComponent(d.location.href) + '&c=' +
     encodeURIComponent(t) + '&bid=' + entryId + '&i=0';
    window.open(url, '_blank', 'width=' + width + ',height=' + height + ',toolbars=0,resizable=1,left=' + leftVal + ',top=' + topVal);
}

function GetMeta(ametaName) {
    var METAs = document.getElementsByTagName("meta");
    for (var i = 0; i < METAs.length; i++) {
        if (METAs[i].name.toLowerCase() == ametaName) { return (METAs[i].content); }
    };
    return "";
}

function AjaxPost(url, postData, successFunc) {
    $.ajax({
        url: url,
        data: postData,
        type: 'post',
        dataType: 'json',
        contentType: 'application/json; charset=utf8',
        success: function (data) {
            //if (data.d) {
            successFunc(data.d);
            //}
        },
        error: function (xhr) {
            //alert("提交出错，请重试。错误信息："+xhr.responseText);
        }
    });
}

/*#region Digg */

var currentDiggType = 0;
var currentDiggEntryId;

function DiggIt(entryId, blogId, diggType) {
    currentDiggEntryId = entryId;
    var diggedType = currentDiggType;
    if (diggedType == 0) {
        ShowDiggMsg('提交中...');
        currentDiggType = diggType;
        AjaxPost("/ws/digg.asmx/digg", '{entryId:' + entryId + ',blogId:' + blogId + ',diggType:' + diggType + '}', OnDiggSuccess);
    }
    else if (diggedType == 1) {
        ShowDiggMsg('您已经推荐过了！');
    }
    else if (diggedType == 2) {
        ShowDiggMsg('您已经反对过了！');
    }
}

function OnDiggSuccess(response) {
    if (response == -1) {
        location.href = "http://passport.cnblogs.com/login.aspx?ReturnUrl=" + location.href;
    }
    else if (response == -2) {
        ShowDiggMsg("您已经评价过该文章！");
    }
    else if (response == 0) {
        ShowDiggMsg('操作失败，请与管理员联系！');
    }
    else {
        if (currentDiggType == 1) {
            $("#digg_count").html(parseInt($("#digg_count").html()) + 1);
        }
        else if (currentDiggType == 2) {
            $("#bury_count").html(parseInt($("#bury_count").html()) + 1);
        }
        ShowDiggMsg("谢谢您的评价！");
    }

}

function CancelDigg(entryId) {
    if (confirm('确认取消吗？')) {
        currentDiggEntryId = entryId;
        if (currentDiggType > 0) {
            ShowDiggMsg('操作中...');
            AjaxPost("/ws/digg.asmx/CancelDigg", '{entryId:' + entryId + ',diggType:' + currentDiggType + '}', OnCancelDiggSuccess);
        }
    }
}

function OnCancelDiggSuccess(response) {
    if (currentDiggType == 1) {
        $("#digg_count").html(parseInt($("#digg_count").html()) - 1);
    }
    else if (currentDiggType == 2) {
        $("#bury_count").html(parseInt($("#bury_count").html()) - 1);
    }
    ShowDiggMsg("取消成功！");
    currentDiggType = 0;
}

function ShowDiggMsg(msg) {
    $("#digg_tips").css("color", "red");
    $("#digg_tips").html(msg);
}

/* #endregion */

function hide_links() {
    document.getElementById('mini_nav_more').style.display = 'none'; document.getElementById('mini_nav_more_link_div').className = 'mini_nav_more_link_hide';
}
function show_links() {
    document.getElementById('mini_nav_more').style.display = 'block'; document.getElementById('mini_nav_more_link_div').className = 'mini_nav_more_link';
}

/* #region Comment */

function clt_enter(event) {
    if (event.ctrlKey && event.keyCode == 13) {
        PostComment();
        return false;
    }
    else {
        return true;
    }
}
function ShowCommentMsg(msg) {
    $("#tip_comment").html(msg);
}

function BindComment(commentId) {
    $("#comment_edit_id").html(commentId);
    ShowCommentMsg("评论内容加载中...");
    AjaxPost('/ws/CommentService.asmx/GetCommentBody', '{commentId:' + commentId + '}', OnBindComment);
}

function OnBindComment(reponse) {
    if (reponse == '') {
        $("#comment_edit_id").html('');
    }
    else {
        var content = reponse.replace(/<br>|<br\/>/gi, "\n");
        $("#tbCommentBody").val(content);
        ShowCommentMsg('');
        $("#btn_comment_submit").val("修改");
        $("#span_comment_canceledit").css("display", "inline");
    }
}

function CancelCommentEdit() {
    if (confirm('确认取消修改吗？')) {
        ResetCommentBox();
    }
}

function ResetCommentBox() {
    $("#btn_comment_submit").val("提交");
    $("#comment_edit_id").html('');
    $("#span_comment_canceledit").css("display", "none");
    $("#tbCommentBody").val('');
}

function UpdateComment(blogId) {
    var comment = {};
    comment.commentId = $("#comment_edit_id").html();
    comment.parentId = $("#span_parent_id").html();
    comment.content = $("#tbCommentBody").val();
    comment.blogId = blogId;
    AjaxPost('/ws/CommentService.asmx/UpdateComment', JSON.stringify(comment), OnUpdateComment);
}

function OnUpdateComment(response) {
    if (response) {
        var commentId = $("#comment_edit_id").html();
        var content = $("#tbCommentBody").val();
        content = escapeHTML(content);
        content = content.replace(/\n/g, "<br/>");
        content = content.replace(/\[quote\]/g, "<fieldset class=\"comment_quote\"><legend>引用</legend>");
        content = content.replace(/\[\/quote\]/g, "</fieldset>");
        $("#comment_body_" + commentId).html(content + " <span style='color:red'>修改成功！</span>");
        var url = location.href;
        if (url.indexOf("#") > 0) {
            url = url.substring(0, url.indexOf("#"));
        }
        location.href = url + "#" + commentId;
        ResetCommentBox();
        ShowCommentMsg("修改成功！");
    }
    else {
        alert("修改失败！");
    }
}

function QuoteComment(commentId, replyTo) {
    //if ($("#span_comment_replyto") == '') {
    $("#span_parentcomment_id").html(commentId);
    $("#span_comment_replyto").html(replyTo);
    //}
    GetQuoteComment(commentId);
}

function GetQuoteComment(commentId) {
    ShowCommentMsg("引用内容加载中...");
    AjaxPost('/ws/CommentService.asmx/GetQuoteComment', '{commentId:' + commentId + '}', OnGetQuoteComment);
}

function OnGetQuoteComment(response) {
    var content = response;
    if (content.length > 300) {
        content = content.substring(0, 300) + "...";
    }
    $("#tbCommentBody").focus();
    $("#tbCommentBody").val($("#tbCommentBody").val() + "[quote]" + content + "[/quote]" + "\n");
    ShowCommentMsg('');
}

function ReplyComment(author, commentId, replyTo) {
	$.getScript('http://common.cnblogs.com/script/encoder.js', function(){
		$("#tbCommentBody").focus();
		$("#tbCommentBody").val("@" + Encoder.htmlDecode(author) + "\n" + $("#tbCommentBody").val());
		$("#span_parentcomment_id").html(commentId);
		$("#span_comment_replyto").html(replyTo);
	});
}

function CommentNotify(commentId) {
    var replyto = $("#span_comment_replyto").html();
    $.ajax({
        url: '/ws/CommentService.asmx/SendCommentNotify',
        data: '{id:"' + replyto + '",commentId:' + commentId + '}',
        type: "post",
        dataType: "json",
        contentType: "application/json; charset=utf8"
    });
}

var currentDelElement;
var currentCommentID;
function DelComment(id, element) {
    if (confirm("确认要删除该评论吗?")) {
        currentDelElement = element;
        currentCommentID = id;
        $(currentDelElement).html("<span style='color:red'>正在删除...</span>");
        $(currentDelElement).removeAttr("href");
        $(currentDelElement).removeAttr("onclick");
        AjaxPost("/ws/CommentService.asmx/DeleteComment", '{commentId:' + id + '}', OnDelComment);
    }
    return false;
}

function OnDelComment(response) {
    if (response) {
        $("#comment_body_" + currentCommentID).html('');
        if (document.getElementById("comment_anchor_" + currentCommentID) != null) {
            document.getElementById("comment_anchor_" + currentCommentID).parentNode.innerHTML = '';
        }
        if (currentDelElement.parentNode != null) {
            currentDelElement.parentNode.innerHTML = "<span style='color:red'>删除成功!</span>";
        }

    }
    else {
        alert('删除失败！');
    }
}

function InsertCodeToEditor(code) {
    $("#tbCommentBody").val($("#tbCommentBody").val() + code);
}

function RefreshPage() {
    //var url = location.href;
    //location.href = AddParamToUrl(url,"id",Math.random());
    location.reload();
    return false;
}

function RefreshCommentList(parentId) {
    $("#span_refresh_tips").show();
    $("#span_refresh_tips").html("正在刷新...");
    $("#span_refresh_tips").css("color", "red");
    $("#lnk_RefreshComments").hide();
    var startId = $("#span_comment_maxid").html();
    if (!startId) startId = 0;
    AjaxPost('/ws/CommentService.asmx/GetNewComments', '{parentId:' + parentId + ',startId:' + startId + '}', OnRefreshCommentList);
    return false;
}

function OnRefreshCommentList(response) {
    if (response == '') {
        $("#divCommentShow").html("<div style=\"color:red;padding:5px;\">暂无新评论，" + new Date() + "</div>");
    }
    else {
        $("#divCommentShow").html(response);
    }
    $("#span_refresh_tips").hide();
    $("#lnk_RefreshComments").show();
}

function RereshComments2(parentId) {
    $("#divCommentShow").html($("#divCommentShow").html() + "<span style='color:red'>评论提交成功！<br/>正在更新评论列表...</span>");
    var startId = $("#span_comment_maxid").html();
    if (!startId) startId = 0;
    AjaxPost('/ws/CommentService.asmx/GetNewComments', '{parentId:' + parentId + ',startId:' + startId + '}', OnRefreshComments2);
    return false;
}

function OnRefreshComments2(response) {
    $("#divCommentShow").html(response);
}

function AddParamToUrl(url, paramName, paramValue) {
    var index = url.indexOf('?');
    if (index > 0) {
        url = url.substring(0, index);
    }
    return url + "?" + paramName + "=" + paramValue;
}

function OpenImageUploadWindow() {
    var uploadUrl = 'http://pic002.cnblogs.com/upload_pic.aspx?returnUrl=http://www.cnblogs.com/InsertCommenImage.htm';
    OpenWindow(uploadUrl, 550, 160, 200);
}

/* #endregion */

/* #region UBB */

$.fn.extend({
    selection: function () {
        var txt = '';
        var doc = this.get(0).document;
        if (doc) {
            var sel = doc.selection.createRange();
            if (sel.text.length > 0)
                txt = sel.text;
        }
        else if (this.get(0).selectionStart || this.get(0).selectionStart == '0') {
            var s = this.get(0).selectionStart;
            var e = this.get(0).selectionEnd;
            if (s != e) {
                txt = this.get(0).value.substring(s, e);
            }
        }
        return $.trim(txt);
    },
    parseHtml: function (t) {
        var doc = this.get(0).document;
        if (doc) {
            this.get(0).focus();
            doc.selection.createRange().collapse;
            this.get(0).document.selection.createRange().text = t;
        }
        else if (this.get(0).selectionStart || this.get(0).selectionStart == '0') {
            var s = this.get(0).selectionStart;
            var e = this.get(0).selectionEnd;
            var val = this.get(0).value;
            var start = val.substring(0, s);
            var end = val.substring(e);
            this.get(0).value = start + t + end;
        }
    }
})

var insertUBB = function (id, html) {
    var val = $('#' + id).selection();
    if (val == '') {
        alert('请选择文字');
    }
    else {
        var end = html;
        if (html.indexOf('=') >= 0)
            end = html.substring(0, html.indexOf('='));
        $('#' + id).parseHtml('[' + html + ']' + val + '[/' + end + ']');
    }
}

function insertIndent(id) {
    var val = $('#' + id).selection();
    if (val == '') {
        $('#' + id).parseHtml("　　");
    }
    else {
        $('#' + id).parseHtml("　　" + val);
    }
}

function insertUbbUrl(id) {
    var p1 = prompt("显示链接的文本.\n如果为空，那么将只显示超级链接地址", "");
    if (p1 != null) {
        var p2 = prompt("http:// 超级链接", "http://");
        if (p2 != '' && p2 != 'http://') {
            if (p1 != '') {
                $('#' + id).parseHtml('[url=' + p2 + ']' + p1 + '[/url]');
            }
            else {
                $('#' + id).parseHtml('[url]' + p2 + '[/url]');
            }
        }
    }
}

function insertUbbImg(id) {
    var p = prompt('请先将图片上传到您的图库中，然后将图片地址拷下粘贴在此：', 'http://');
    if (p == null || $.trim(p) == '' || p.toLowerCase() == 'http://')
        return;
    $('#' + id).parseHtml('[img]' + p + '[/img]');
}

function insertUploadImg(imgUrl) {
    $('#tbCommentBody').parseHtml('[img]' + imgUrl + '[/img]');
}

function insertUbbCode() {
    var c_width = 450;
    var c_height = 400;
    var leftVal = (screen.width - c_width) / 2;
    var topVal = (screen.height - c_height) / 2;
    var codeWindow = window.open('/SyntaxHighlighter.aspx', '_blank', 'width=' + c_width + ',height=' + c_height + ',toolbars=0,resizable=1,left=' + leftVal + ',top=' + topVal);
    codeWindow.focus();
}

/* #endregion */

function escapeHTML(str) {
    var div = document.createElement('div');
    var text = document.createTextNode(str);
    div.appendChild(text);
    return div.innerHTML;
}

function GetRecentIng(spaceUserId) {
    $.ajax({
        url: '/WS/PublicUserService.asmx/GetIngList',
        data: '{spaceUserId:' + spaceUserId + '}',
        type: 'post',
        dataType: 'json',
        contentType: 'application/json; charset=utf-8',
        cache: false,
        success: function (data) {
            $("#author_profile_ing").html(data.d);
        },
        error: function (xhr) {
            $("#author_profile_ing").html("读取闪存出错：" + xhr.responseText);
        }
    });
}

//#region Code Highlight

function cnblogs_code_collapse(element) {
    if (element.children('div.cnblogs_code_open').css('display') != 'none') {
        element.children('div.cnblogs_code_open').css('display', 'none');
        element.children('img.code_img_opened').css('display', 'none');
        element.children('img.code_img_closed').css('display', 'inline');
    }
    else {
        element.children('div.cnblogs_code_open').css('display', 'block');
        element.children('img.code_img_opened').css('display', 'inline');
        element.children('img.code_img_closed').css('display', 'none');
    }
}

function cnblogs_code_show(id) {
    var codediv = $('#cnblogs_code_open_' + id);
    if (codediv.css('display') == 'none') {
        codediv.show();
        $('#code_img_opened_' + id).show();
        $('#code_img_closed_' + id).hide();
        if (!$(codediv).find("span.cnblogs_code_copy").length) {
            showCopyCode(codediv);
        }
    }
}
function cnblogs_code_hide(id, event) {
    if ($('#cnblogs_code_open_' + id).css('display') != 'none') {
        $('#cnblogs_code_open_' + id).hide();
        $('#code_img_opened_' + id).hide();
        $('#code_img_closed_' + id).show();
        if (event.stopPropagation) {
            event.stopPropagation();
        }
        else if (window.event) {
            window.event.cancelBubble = true;
        }
    }
}

function code_collapse_toggle(element) {
    $(element).toggle();
    var id = element.id;
    if (IsCodeCollapseNode(id, '_Open_Image')) {
        $("#" + id.replace('_Open_', '_Closed_')).toggle();
        $("#" + id.replace('_Open_Image', '_Open_Text')).toggle();
        $("#" + id.replace('_Open_Image', '_Closed_Text')).toggle();
    }
    else if (IsCodeCollapseNode(id, '_Closed_Image')) {
        $("#" + id.replace('_Closed_', '_Open_')).toggle();
        $("#" + id.replace('_Closed_Image', '_Open_Text')).toggle();
        $("#" + id.replace('_Closed_Image', '_Closed_Text')).toggle();
    }
}

function fix_code_collapse_img(img) {
    if (IsCodeCollapseNode(img.id, '_Open_Image')) {
        var id1 = img.id.replace('_Open_Image', '_Closed_Image');
        var id2 = img.id.replace('_Open_Image', '_Open_Text');
        var id3 = img.id.replace('_Open_Image', '_Closed_Text');
        img.onclick = function () { $(this).hide(); $('#' + id1 + '').show(); $('#' + id2 + '').hide(); $('#' + id3 + '').show(); };
    }
    else if (IsCodeCollapseNode(img.id, '_Closed_Image')) {
        var id1 = img.id.replace('_Closed_Image', '_Open_Image');
        var id2 = img.id.replace('_Closed_Image', '_Open_Text');
        var id3 = img.id.replace('_Closed_Image', '_Closed_Text');
        img.onclick = function () { $(this).hide(); $('#' + id1 + '').show(); $('#' + id2 + '').show(); $('#' + id3 + '').hide(); };
    }
}

function IsCodeCollapseNode(id, tag) {
    return id.indexOf(tag) >= 0;
}

function fix_code_collapse_span(element) {
    var regex_c_text = /Codehighlighter1_\d+_\d+_Closed_Text/ig;
    if (regex_c_text.test(element.id)) {
        $(element).hide();
    }
    var regex_o_text = /Codehighlighter1_\d+_\d+_Open_Text/ig;
    if (regex_o_text.test(element.id)) {
        $(element).show();
    }
}

//For old code collapse 
function change_onclick(element, clickCode) {
    if (clickCode) {
        var newclick = eval("(function(){" + clickCode + "});");
        $(element).attr('onclick', '').click(newclick);
    }
}

$(function () {
    var hlCodes = $("#cnblogs_post_body div.cnblogs_code");
    var lineNumberTextPattern = /^\s*1/gi;
    var lineNubmerOtherPattern = /<span style=\"color: #008080;?\">\s*(&nbsp;)?(\d+)<\/span>/gi;
    var brPattern = /<br\s*\/?>/gi;

    if (hlCodes.length) {
        loadEncoderJs();
        $.each(hlCodes, function () {
            if (lineNumberTextPattern.test($(this).text())) {
                var htmlContent = $(this).html();
                if ($.browser.msie) {
                    if (htmlContent.indexOf('<pre>') > -1 && brPattern.test(htmlContent)) {
                        htmlContent = htmlContent.replace(brPattern, '\r\n');
                        $(this).html(htmlContent);
                    }
                    //showRemoveLineNumber(this);
                    //showCopyCode(this);
                }
//                else if ($.browser.mozilla) {
//                    htmlContent = htmlContent.replace(lineNubmerOtherPattern, '<span class="codeLineNumber">$2</span>');
//                    $(this).html(htmlContent);
//                }
//                else {
//                    htmlContent = htmlContent.replace(lineNubmerOtherPattern, '<li><span>')
//                                                .replace(/\n<li/gi, '</span></li><li');
//                    //.replace(/<pre>/gi, '<pre><ol>').replace(/<\/pre>/gi, '</ol></pre>');
//                    $(this).html('<ol>' + htmlContent + '</ol>');
//                }
                //showCopyCode(this);
            }
            showCopyCode(this);
        });
        
    }
});

function showRemoveLineNumber(element) {
    $(element).append('<div class="cnblogs_code_toolbar"><span class="cnblogs_code_copy"><a href="javascript:void(0);" onclick="removeLineNumber(this);return false;">消除行号</a></span>');
}

function showCopyCode(element) {
    //loadEncoderJs();
    if ($(element).height() > 120) {
        var copyCodeToolbar = '<div class="cnblogs_code_toolbar"><span class="cnblogs_code_copy"><a href="javascript:void(0);" onclick="copyCnblogsCode(this)" title="复制代码"><img src="http://common.cnblogs.com/images/copycode.gif" alt="复制代码"/></a></span>';
        $(element).prepend(copyCodeToolbar).append(copyCodeToolbar);
    }
}

function removeLineNumber(element) {
    var codeContainer =  $(element).parent().parent().parent();
    var lineNumberIePattern = /<span style=\"color: #008080;?\">\s*(&nbsp;)?(\d+)<\/span>/gi;
    var codeHtml = $(codeContainer).html().replace(lineNumberIePattern, '');
    $(codeContainer).html(codeHtml);
}

function loadEncoderJs() {
    var encoderJs = document.createElement('script');
    encoderJs.type = 'text/javascript';
    encoderJs.src = 'http://common.cnblogs.com/script/encoder.js';
    var node = document.getElementsByTagName('script')[0];
    node.parentNode.insertBefore(encoderJs, node);
}

function copyCnblogsCode(element) {
    var codeContainer = getCnblogsCodeContainer(element);
    var cbCode = getCnblogsCodeText(codeContainer);
    var textarea = document.createElement('textarea');
    $(textarea).val(cbCode); //.select();
    $(textarea).css("width", $(codeContainer).width());
    var height = $(codeContainer).height() * 0.8;
    if (height > 600) height = 600;
    $(textarea).css("height", height); 
    $(textarea).css("font-family", "Courier New");
    $(textarea).css("font-size", "12px");
    $(textarea).css("line-height", "1.5");
    $(codeContainer).html(textarea);
    $(textarea).select();
	$("<div>按 Ctrl+C 复制代码</div>").insertBefore($(textarea));
    $("<div>按 Ctrl+C 复制代码</div>").insertAfter($(textarea));
}

function getCnblogsCodeContainer(element) {
    var codeContainer = $(element).closest("pre");    
    if (codeContainer.length == 0) {
        codeContainer = $(element).closest("div.cnblogs_code");
    }
    return codeContainer;
}

function getCnblogsCodeText(codeContainer) {
    var cbCode = '\n' + $(codeContainer).html()
    .replace(/&nbsp;/g, ' ')
    .replace(/<br\s*\/?>/ig, '\n')
    .replace(/<[^>]*>/g, '');
    cbCode = cbCode.replace(/\n(\s*\d+)/ig, '\n');
    cbCode = cbCode.replace(/\r\n/g, '\n');
    if (typeof Encoder != undefined) {
        cbCode = Encoder.htmlDecode(cbCode);
    }
    cbCode = $.trim(cbCode);
    return cbCode;
}

function showRunCode(element) {
    var codeCopyDiv = $(element).find("div.cnblogs_code_toolbar");
    if (codeCopyDiv.length) {
        $(codeCopyDiv).append('<span class="cnblogs_code_runjs"><a href="javascript:void(0);" onclick="runJsCode(this)">运行代码</a></span>');
    }
}

function runJsCode(element) {
    var codeContainer = getCnblogsCodeContainer(element);
    var cbCode = getCnblogsCodeText(codeContainer);
    var newwin = window.open('', "_blank", '');
    newwin.document.open('text/html', 'replace');
    newwin.opener = null;
    newwin.document.write(cbCode);
    newwin.document.close();
}

//#endregion

function zzk_go() {
    var keystr = encodeURIComponent("blog:" + blogapp + " " + document.getElementById('q').value);
    window.location = "http://zzk.cnblogs.com/s?w=" + keystr;
}
function zzk_go_enter(event) {
    if (event.keyCode == 13) {
        zzk_go();
        return false;
    }
}
function google_go() {
    var keystr = encodeURIComponent("site:www.cnblogs.com/" + blogapp + "/ " + document.getElementById('google_q').value);
    window.location = "http://www.cnblogs.com/search.aspx?keyword=" + keystr;
}
function google_go_enter(event) {
    if (event.keyCode == 13) {
        google_go();
        return false;
    }
}
function open_link(url) {
    window.open(url);
    return false;
}
function GetJobList() {
    try {
        $("#job_list").html('数据加载中...');
        $.ajax({
            url: '/ws/BlogAjaxService.asmx/GetJobList',
            data: '{}',
            type: 'post',
            dataType: 'json',
            contentType: 'application/json; charset=utf8',
            success: function (data) {
                $("#job_list").html(data.d);
            }
        });
    } catch (e) { }
}

function login() {
    location.href = "http://passport.cnblogs" + getHostPostfix() + "/login.aspx?ReturnUrl=" + location.href;
    return false;
}

function logout() {
    if (confirm("确认注销吗？")) {
        location.href = "http://passport.cnblogs" + getHostPostfix() + "/logout.aspx?ReturnUrl=" + location.href;
    }
    return false;
}

function register() {
    location.href = "http://passport.cnblogs" + getHostPostfix() + "/register.aspx?ReturnUrl=" + location.href;
    return false;
}

function getHostPostfix() {
    var hostname = location.hostname;
    hostname = hostname.substring(hostname.lastIndexOf("."), hostname.length);
    return hostname;
}

var c_has_follwed = false;

function c_follow() {
    if (!isLogined) {
        login();
    }
    if (c_has_follwed) {
        alert("你已经关注过该博主！");
        return false;
    }
    if (!confirm("您确定要关注该博主吗？关注之后，就可以方便地看到他的博客了:)"))
        return false;
    $("#author_profile_follow").html("<span class='color:red'>正在处理中...</span>");
    $.ajax({
        url: '/ws/UserFollow.asmx/FollowUser',
        data: '{targetUserId:"' + cb_blogUserGuid + '"}',
        type: 'post',
        dataType: 'json',
        contentType: 'application/json; charset=utf-8',
        cache: false,
        success: function (data) {
            if (data.d) {
                show_follow_msg("关注成功！");
                green_channel_success($("#green_channel_follow"), '谢谢关注！');
                //关注邮件通知
            }
            else {
                show_follow_msg("添加关注失败，请联系管理员。");
            }
        },
        error: function (xhr) {
            show_follow_msg("发生了错误：" + xhr.responseText);
        }
    });
    return true;
}

function remove_follow() {
    if (!confirm("您确定要取消关注吗？"))
        return;
    $("#author_profile_follow").html("<span style='color:red'>正在处理中...</span>");
    $.ajax({
        url: '/ws/UserFollow.asmx/RemoveFollow',
        data: '{targetUserId:"' + cb_blogUserGuid + '"}',
        type: 'post',
        dataType: 'json',
        contentType: 'application/json; charset=utf-8',
        cache: false,
        success: function (data) {
            if (data.d) {
                show_follow_msg('成功取消关注。');
            }
            else {
                show_follow_msg("取消关注失败，请联系管理员。");
            }
        },
        error: function (xhr) {
            show_follow_msg("发生了错误：" + xhr.responseText);
        }
    });
}

function show_follow_msg(msg) {
    $("#author_profile_follow").html('<span style="color:red">' + msg + '</span>');
}

function green_channel_success(element, msg) {
    $(element).replaceWith('<span style="color:red">' + msg + '</span>');
}

function LoadPostInfoBlock(blogId, entryId, blogApp, blogUserGuid) {
    $.ajax({
        url: "/WS/BlogDetailWs.asmx/LoadPostInfoBlock",
        type: "post",
        dataType: "json",
        contentType: "application/json; charset=utf-8",
        data: '{"blogId":' + blogId + ',"entryId":' + entryId + ',"blogApp":"' + blogApp + '","blogUserGuid":"' + blogUserGuid + '"}',
        success: LoadPostInfoBlock_CallBack
    });
}

function LoadPostInfoBlock_CallBack(data) {
    if (data.d) {
        $("#BlogPostCategory").html(data.d.Categories);
        //$("#EntryTag").html(data.d.Tags);

        currentDiggType = data.d.DiggType;
        if (data.d.DiggType == 1) {
            $("#green_channel_digg").html("已推荐");
            $("#green_channel_digg").attr('onclick', '').click(eval("(function(){alert('您已经推荐过该文章:)')});"));
            $("#digg_tips").html("您已推荐过，<a href='javascript:void(0);' onclick='return CancelDigg(cb_entryId)' class='digg_gray'>取消</a>");
        }
        else if (data.d.DiggType == 2) {
            $("#digg_tips").html("(您已反对过，<a href='javascript:void(0);' onclick='return CancelDigg(cb_entryId)' class='digg_gray'>取消</a>)");
        }
        else {
            $("#digg_tips").html("(请您对文章做出评价)");
        }
        $("#digg_count").html(data.d.DiggCount);
        $("#bury_count").html(data.d.BuryCount);
        $("#div_digg").show();

        c_has_follwed = data.d.IsFollowing;
        if (c_has_follwed) {
            $("#green_channel_follow").html("已关注");
            $("#green_channel_follow").attr('onclick', '').click(eval("(function(){alert('您已经关注过我了:)')});"));
            $("#author_profile_follow").html("我在关注他 <a href=\"javascript:void(0);\" onclick=\"remove_follow();\">取消关注</a>");

        }
        else {
            $("#author_profile_follow").html("<a href=\"javascript:void(0);\" onclick=\"c_follow();return false;\">+加关注</a>");
        }

        $("#green_channel").show();

        if (data.d.IconName) {
            $("#author_profile_info").prepend('<a href="' + data.d.HomeUrl + '" target="_blank"><img src="' + data.d.IconName + '" class="author_avatar" alt=""/></a>');
        }
        $("#author_profile_detail").append('<a href="' + data.d.HomeUrl + '">' + data.d.DisplayName + '</a><br/>');
        $("#author_profile_detail").append('<a href="' + data.d.HomeUrl + 'followees">关注 - ' + data.d.FollowingCount + '</a><br/>');
        $("#author_profile_detail").append('<a href="' + data.d.HomeUrl + 'followers">粉丝 - ' + data.d.FollowerCount + '</a>');

        if (data.d.Honor) {
            $("#author_profile_honor").html(data.d.Honor);
        }
    }
}

function GetPrevNextPost(postId, blogId, dateCreated) {
    $.ajax({
        url: '/ws/BlogDetailWs.asmx/GetPrevNext',
        data: '{"postId":' + postId + ',"blogId":' + blogId + ',"dateCreated":"' + dateCreated + '"}',
        type: 'post',
        dataType: 'json',
        contentType: 'application/json; charset=utf-8',
        cache: false,
        success: function (data) {
            if (data.d) {
                $("#post_next_prev").html(data.d);
            }
        }
    });
}

function GetHistoryToday(blogId, blogApp, dateCreated) {
    $.ajax({
        url: '/ws/BlogDetailWs.asmx/GetHistoryToday',
        data: '{"blogId":' + blogId + ',"blogApp":"' + blogApp + '","dateCreated":"' + dateCreated + '"}',
        type: 'post',
        dataType: 'json',
        contentType: 'application/json; charset=utf-8',
        cache: false,
        success: function (data) {
            if (data.d) {
                $("#HistoryToday").html(data.d);
            }
        }
    });
}

var cnblogs = {};
cnblogs.UserManager = {};

cnblogs.UserManager.GetLoginUrl = function () {
    return "http://" + location.hostname.replace('www.', 'passport.') + '/' + "login.aspx?ReturnUrl=" + location.href;
}

cnblogs.UserManager.GetFollowStatus = function (blogUserGuid) {
    $.ajax({
        url: '/mvc/Follow/GetFollowStatus.aspx',
        data: '{"blogUserGuid":"' + blogUserGuid + '"}',
        dataType: 'text',
        type: 'post',
        contentType: 'application/json; charset=utf-8',
        success: function (data) {
            $("#p_b_follow").html(data);
            //$("#p_b_follow").parent().append('<div id="p_b_ing"><a href="http://home.cnblogs.com/ing/my/">我的闪存</a></div>');
        }
    });
}

cnblogs.UserManager.FollowBlogger = function (blogUserGuid) {
    $("#p_b_follow").html("提交中...").css("color", "red");
    $.ajax({
        url: '/mvc/Follow/FollowBlogger.aspx',
        data: '{"blogUserGuid":"' + blogUserGuid + '"}',
        dataType: 'text',        
        type: 'post',    
        contentType: 'application/json; charset=utf-8',
        success: function (data) {
            if (data == '未登录') {
                location.href = cnblogs.UserManager.GetLoginUrl();
            }
            else {
                $("#p_b_follow").html(data);
            }
        }
    });
}

cnblogs.UserManager.RemoveFlow = function (blogUserGuid) {
    $("#p_b_follow").html("提交中...").css("color", "red");
    $.ajax({
        url: '/mvc/Follow/RemoveFollow.aspx',
        data: '{"blogUserGuid":"' + blogUserGuid + '"}',
        dataType: 'text',
        type: 'post',
        contentType: 'application/json; charset=utf-8',
        success: function (data) {
            if (data == '未登录') {
                location.href = cnblogs.UserManager.GetLoginUrl();
            }
            else {
                $("#p_b_follow").html(data);
            }
        }
    });
}

function tsina_a() {
    var s = screen;
    var d = document;
    var e = encodeURIComponent;
    var f = 'http://v.t.sina.com.cn/share/share.php?', u = d.location.href, p = ['url=', e(u), '&title=', e(d.title)].join('');
    if (!window.open([f, p].join(''), 'mb', ['toolbar=0,status=0,resizable=1,width=620,height=450,left=', (s.width - 620) / 2, ',top=', (s.height - 450) / 2].join(''))) u.href = [f, p].join('');
}

function ShareToTsina() {
    if (/Firefox/.test(navigator.userAgent)) { setTimeout(tsina_a, 0) } else { tsina_a() };
}

$(function () {
    var showFlag = new Array();
    if (document.getElementById("RecentCommentsBlock")) {
        showFlag.push("ShowRecentComment");
    }
    if (document.getElementById("TopViewPostsBlock")) {
        showFlag.push("ShowTopViewPosts");
    }
    if (document.getElementById("TopFeedbackPostsBlock")) {
        showFlag.push("ShowTopFeedbackPosts");
    }
    if (document.getElementById("TopDiggPostsBlock")) {
        showFlag.push("ShowTopDiggPosts");
    }
    //    if(document.getElementById("widget_ing")){
    //        showFlag.push("ShowRecentIng");
    //    }

    $.ajax(
    {
        url: '/mvc/Blog/GetBlogSideBlocks.aspx',
        data: '{"blogApp":"' + currentBlogApp + '","showFlag":"' + showFlag.join(",") + '"}',
        type: 'post',
        dataType: 'json',
        contentType: 'application/json; charset=utf-8',
        success: function (data) {
            if (data) {
                //$("#widget_ing").html(data.RecentIng);
                $("#RecentCommentsBlock").html(data.RecentComments);
                $("#TopViewPostsBlock").html(data.TopViewPosts);
                $("#TopFeedbackPostsBlock").html(data.TopFeedbackPosts);
                $("#TopDiggPostsBlock").html(data.TopDiggPosts);
            }
        }
    }
    );
});


function showEditorOpt() {
    if (cb_entryId) {
        $.ajax({
            url: '/mvc/Blog/GetEditorOpt.aspx',
            data: '{"url":"' + location.href + '","postId":' + cb_entryId + '}',
            type: 'post',
            dataType: 'json',
            contentType: 'application/json; charset=utf-8',
            success: function (data) {
                if (data) {
                    $("#site_editor_opt").html(data);
                }
            }
        });
    }
}

function outFromAggHome() {
    $.ajax({
        url: '/mvc/Blog/RemoveFromSiteHome.aspx',
        data: '{"postId":"' + cb_entryId + '"}',
        type: 'post',
        dataType: 'json',
        contentType: 'application/json; charset=utf-8',
        success: function (data) {
            if (data) {
                $("#site_editor_opt").html("<span style='color:red'>操作成功！</span>");
            }
        }
    });
}

//#region New Comment

var commentManager = {};
commentManager.postUrl = '';
commentManager.postTitle = '';

commentManager.loadCommentForm = function () {
    //commentManager.postUrl = location.href; //$("#cb_post_title_url").attr("href");
    //commentManager.postTitle = $("#cb_post_title_url").html();
    var ajaxParam = {};
    ajaxParam.postId = cb_entryId;
    ajaxParam.blogApp = currentBlogApp;
    $("#comment_form_container").html("<span style='color:red'>评论框加载中...</span>");
    $.ajax({
        url: '/mvc/Blog/CommentForm.aspx',
        data: JSON.stringify(ajaxParam),
        dataType: 'html',
        type: 'post',
        contentType: 'application/json; charset=utf-8',
        success: function (data) {
            if (data) {
                $("#comment_form_container").html(data);
                $("#tbCommentBody").bind('keydown', function (event) {
                    commentManager.ctlEnterPost(event);
                });
                $("#btn_comment_submit").bind('click', function () {
                    commentManager.postComment();
                    return false;
                });
            }
        },
        error: function (xhr) {
            $("#comment_form_container").html("<span style='color:red'>评论框加载失败，请与管理员联系。</span>");
        }
    });
}

commentManager.postComment = function () {
    if ($("#btn_comment_submit").val() == "修改" && $("#comment_edit_id").html != '') {
        commentManager.UpdateComment();
    }
    else {
        commentManager.PostNewComment();
    }
}

commentManager.ctlEnterPost = function (event) {
    if (event.ctrlKey && event.keyCode == 13) {
        commentManager.postComment();
        return false;
    }
    else {
        return true;
    }
}

commentManager.PostNewComment = function () {
    var content = $.trim($("#tbCommentBody").val());
    if (!content) {
        alert('请输入评论内容！');
        return;
    }
    if (content.length > 4000) {
        alert('评论内容过长，超过4000个字数限制！当前长度：' + content.length);
        return;
    }

    if ($("#span_comment_posted").html() != '' && $("#span_comment_posted").html() == content) {
        alert("该评论已发表过!");
        return;
    }

    $("#tip_comment").html("评论提交中...");
    $("#span_comment_posted").html(content);
    var comment = {};
    comment.postId = cb_entryId;
    comment.Body = content;
    var parentCommentId = $("#span_parentcomment_id").text();
    if (/(\d)/.test(parentCommentId)) {
        comment.ParentCommentID = parentCommentId;
    } else {
        comment.ParentCommentID = 0;
    }
    var startDate = new Date();
    $.ajax({
        url: '/mvc/PostComment/New.aspx',
        data: JSON.stringify(comment),
        type: "post",
        dataType: "json",
        contentType: "application/json; charset=utf8",
        success: function (data) {
            if (data) {
                if (data.IsSuccess) {
                    var dt = (new Date()).getTime() - startDate;
                    ShowCommentMsg("感谢您的回复:)" + " 提交耗时" + dt + "毫秒");
                    $("#tbCommentBody").val('');
                    $("#divCommentShow").html($("#divCommentShow").html() + data.Message);
                } else {
                    ShowCommentMsg(data.Message);
                    $("#span_comment_posted").html('');
                }
            } else {
                var errorMsg = "抱歉！评论提交失败！请与管理员联系。";
                ShowCommentMsg(errorMsg);
                $("#span_comment_posted").html('');
            }
        },
        error: function (xhr) {
            ShowCommentMsg("抱歉！评论提交失败！错误信息：" + xhr.responseText);
            $("#span_comment_posted").html('');
        }
    });
}

commentManager.UpdateComment = function () {
    var comment = {};
    comment.commentId = parseInt($("#comment_edit_id").html());
    comment.body = $("#tbCommentBody").val();

    $.ajax({
        url: '/mvc/PostComment/Update.aspx',
        data: JSON.stringify(comment),
        type: "post",
        dataType: "json",
        contentType: "application/json; charset=utf8",
        success: function (data) {
            if (data) {
                if (data.IsSuccess) {
                    ShowCommentMsg("修改成功");
                    $("#comment_body_" + comment.commentId).html(data.Message);
                    commentManager.ResetCommentBox();
                } else {
                    ShowCommentMsg(data.Message);
                }
            } else {
                var errorMsg = "抱歉！评论修改失败！请与管理员联系。";
                ShowCommentMsg(errorMsg);
            }
        },
        error: function (xhr) {
            ShowCommentMsg("抱歉！评论修改失败！错误信息：" + xhr.responseText);
        }
    });
}

commentManager.Subscribe = function () {
    if (confirm("确认订阅吗？订阅后有新评论时会邮件通知您")) {
        var postId = cb_entryId;
        var blogId = cb_blogId;
        $("#commentbox_opt_sub").html("提交中...");
        $("#commentbox_opt_sub").css("color", "red");
        $("#commentbox_opt_sub").removeAttr("onclick");
        $.ajax({
            url: '/mvc/Subscribe/SubscribeComment.aspx',
            data: '{"blogId":' + blogId + ',"postId":' + postId + '}',
            type: "post",
            dataType: "json",
            contentType: "application/json; charset=utf8",
            success: function (data) {
                if (data) {
                    $("#commentbox_opt_sub").html("订阅成功");
                }
                else {
                    $("#commentbox_opt_sub").html("订阅失败");
                }
            }
        });
    }
}

commentManager.Unsubscribe = function () {
    var postId = cb_entryId;
    $("#commentbox_opt_unsub").html("提交中...");
    $("#commentbox_opt_unsub").css("color", "red");
    $("#commentbox_opt_unsub").removeAttr("onclick");
    $.ajax({
        url: '/mvc/Subscribe/UnsubscribeComment.aspx',
        data: '{"postId":' + postId + '}',
        type: "post",
        dataType: "json",
        contentType: "application/json; charset=utf8",
        success: function (data) {
            if (data) {
                $("#commentbox_opt_unsub").html("取消订阅成功");
            }
            else {
                $("#commentbox_opt_unsub").html("取消订阅失败");
            }
        }
    });
}

commentManager.ResetCommentBox = function () {
    $("#btn_comment_submit").val("提交评论");
    $("#comment_edit_id").html('');
    //$("#span_comment_canceledit").css("display", "none");
    $("#tbCommentBody").val('');
}

commentManager.loadMailSubscribeOperation = function () {
    $("#commentbox_opt").append('<a href="">订阅回复</a>');
}

//commentManager.CommentNotify = function (commentId) {
//    var replyto = $("#span_comment_replyto").html();
//    $.ajax({
//        url: '/mvc/CommentService.aspx/SendCommentNotify',
//        data: '{"id":"' + replyto + '","commentId":' + commentId + '}',
//        type: "post",
//        dataType: "json",
//        contentType: "application/json; charset=utf8"
//    });
//}

function SubscribeComment() {
    $("#<%= lnkSubscribe.ClientID %>").html("<span style='color:red'>订阅操作中...</span>");
    AjaxPost("/ws/CommentService.asmx/SubscribeComment", "{entryId:" + cb_entryId + ",blogId:" + cb_blogId + "}", OnSubscribeSuccess);
    return false;
}

function OnSubscribeSuccess(response) {
    if (response) {
        $("#<%= lnkSubscribe.ClientID %>").html("<span style='color:red'>订阅成功</span>");
        $("#<%= lnkSubscribe.ClientID %>").removeAttr("href");
        $("#<%= lnkSubscribe.ClientID %>").removeAttr("onclick");
    }
    else {
        $("#<%= lnkSubscribe.ClientID %>").html("<span style='color:red'>订阅失败</span>");
    }
}

function CancelCommentSubscribe() {
    $("#<%= lnkSubscribe.ClientID %>").html("<span style='color:red'>取消操作中...</span>");
    AjaxPost("/ws/CommentService.asmx/CancelCommentSubscribe", "{entryId:" + cb_entryId + "}", OnCancelSubscribeSuccess);
    return false;
}

function OnCancelSubscribeSuccess(response) {
    if (response) {
        $("#<%= lnkSubscribe.ClientID %>").html("<span style='color:red'>取消成功</span>");
        $("#<%= lnkSubscribe.ClientID %>").removeAttr("href");
        $("#<%= lnkSubscribe.ClientID %>").removeAttr("onclick");
    }
    else {
        $("#<%= lnkSubscribe.ClientID %>").html("<span style='color:red'>取消操作失败</span>");
    }
}

//#endregion
